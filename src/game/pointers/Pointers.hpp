#pragma once
#include <d3d12.h>
#include <dxgi1_4.h>
#include <windows.h>


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
	};

	struct Pointers : PointerData
	{
		bool Init();
	};

	inline NewBase::Pointers Pointers;
}
