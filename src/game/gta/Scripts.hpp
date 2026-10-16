#pragma once
#include "util/Joaat.hpp"
#include "types/script/scrProgram.hpp"
#include "types/script/scrThread.hpp"

namespace NewBase::Scripts
{
	extern rage::scrThread* FindScriptThread(joaat_t hash);
	extern void RunAsScript(rage::scrThread* thread, std::function<void()> callback);
}
