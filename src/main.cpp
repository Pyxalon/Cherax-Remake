#include "common.hpp"
#include "core/backend/ScriptMgr.hpp"
#include "core/backend/FiberPool.hpp"
#include "core/filemgr/FileMgr.hpp"
#include "core/hooking/Hooking.hpp"
#include "core/memory/ModuleMgr.hpp"
#include "core/renderer/D3D12Hook.hpp"
#include "core/renderer/Renderer.hpp"
#include "game/frontend/GUI.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/backend/NativeHooks.hpp"


namespace NewBase
{
	DWORD Main(void*)
	{
		const auto documents = std::filesystem::path(std::getenv("USERPROFILE")) / "Documents";
		FileMgr::Init(documents / "HellBase");

		LogHelper::Init("henlo", FileMgr::GetProjectFile("./cout.log").Path());

		if (!ModuleMgr.LoadModules())
			goto unload;
		if (!Pointers.Init())
			goto unload;
		if (!D3D12Hook::Init())
			goto unload;
		Renderer::Init();
		while (!Renderer::IsInitialized())
			std::this_thread::sleep_for(100ms);
		GUI::Init();

		Hooking::Init();
		ScriptMgr::Init();

		ScriptMgr::AddScript(std::make_unique<Script>(&NativeHooks::RunScript)); // runs once
		ScriptMgr::AddScript(std::make_unique<Script>(&GUI::RunScript));
		FiberPool::Init(16);

		while (g_Running)
		{
			std::this_thread::sleep_for(100ms);
		}

	unload:
		Hooking::Destroy();
		Renderer::Destroy();
		LogHelper::Destroy();

		CloseHandle(g_MainThread);
		FreeLibraryAndExitThread(g_DllInstance, EXIT_SUCCESS);

		return EXIT_SUCCESS;
	}
}

BOOL WINAPI DllMain(HINSTANCE dllInstance, DWORD reason, void*)
{
	using namespace NewBase;

	DisableThreadLibraryCalls(dllInstance);

	if (reason == DLL_PROCESS_ATTACH)
	{
		g_DllInstance = dllInstance;

		g_MainThread = CreateThread(nullptr, 0, Main, nullptr, 0, &g_MainThreadId);
	}
	return true;
}
