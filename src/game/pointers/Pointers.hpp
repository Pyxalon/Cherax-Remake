#pragma once
#include <d3d12.h>
#include <dxgi1_4.h>
#include <windows.h>
#include "types/script/scrProgram.hpp"
#include "types/script/scrThread.hpp"
#include "types/rage/atArray.hpp":

namespace NewBase
{
	struct PointerData
	{
		IDXGISwapChain1** SwapChain;
		ID3D12CommandQueue** CommandQueue;
		HWND* Hwnd;
		PVOID WndProc;
		std::uint32_t* ScreenResX;
		std::uint32_t* ScreenResY;
		PVOID InitNativeTables;
		PVOID RunScriptThreads;
		rage::scrProgram** ScriptPrograms;
		rage::atArray<rage::scrThread*>* ScriptThreads;
		bool* IsSessionStarted;
		std::uint32_t* NetworkTime;
		std::uint32_t* GameTimer;
	};

	struct Pointers : PointerData
	{
		bool Init();
	};

	inline NewBase::Pointers Pointers;
}
