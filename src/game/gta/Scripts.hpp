#pragma once
#include "util/Joaat.hpp"
#include "game/gta/data/StackSizes.hpp"

namespace NewBase::Scripts
{
	extern rage::scrThread* FindScriptThread(joaat_t hash);
	extern void RunAsScript(rage::scrThread* thread, std::function<void()> callback);
}
