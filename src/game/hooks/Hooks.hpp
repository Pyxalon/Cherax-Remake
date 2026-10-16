#pragma once
#include <d3d11.h>
#include "types/script/scrProgram.hpp"

namespace NewBase::Hooks
{
	namespace Window
	{
		extern LRESULT WndProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam);
	}

	namespace RawInput
	{
		extern UINT GetRawInputData(HRAWINPUT hRawInput, UINT uiCommand, LPVOID pData, PUINT pcbSize, UINT cbSizeHeader);
	}

	namespace Script
	{
		extern bool RunScriptThreads(int ops_to_execute);
		extern void InitNativeTables(rage::scrProgram* program);
	}
}
