#pragma once
#include "game/frontend/GUI.hpp"
#include "fonts.hpp"
#include "imgui_internal.h"

namespace NewBase::Menu
{
	extern void Init();
	extern void SetupFonts();
	extern void SetupStyle();
	extern void AddNotification(const char* format, ...);
	extern void DrawNotifications();
	extern void Self();
	extern void DrawChild(ImVec2 size, ImVec2 position, const char* text);
	extern void EndChild();
	namespace Font
	{
		inline ImFont* titleFont;
		inline ImFont* textFont;
		inline ImFont* iconFont;
	}
	inline int currentSubmenu;
	inline std::vector<const char*> submenuList = {ICON_FA_USER, ICON_FA_USERS, ICON_FA_NETWORK_WIRED, ICON_FA_PERSON_CIRCLE_PLUS, ICON_FA_CAR, ICON_FA_GUN, ICON_FA_SACK_DOLLAR, ICON_FA_CIRCLE_QUESTION, ICON_FA_SHIELD_HALVED, ICON_FA_GLOBE, ICON_FA_GEAR, ICON_FA_TERMINAL, ICON_FA_PUZZLE_PIECE};
}
