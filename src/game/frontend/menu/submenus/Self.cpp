#include "../Menu.hpp"
#include "game/gta/Natives.hpp"

void NewBase::Menu::Self()
{
	bool godmode = false;
    if (ImGui::BeginTabBar("Tabs")) {
        if (ImGui::BeginTabItem("General")) {
            ImVec2 windowSize = ImGui::GetWindowSize();
            DrawChild(ImVec2(windowSize.x / 2, windowSize.y - 50.f), ImVec2(0.f, 40.f), "General");

            if (ImGui::Button("Clear Wanted"))
			{
				Menu::AddNotification("Test Notification");
			}

            if (ImGui::Button("Money"))
			{
			}

            EndChild();

            DrawChild(ImVec2(windowSize.x / 2 - 5.f, windowSize.y / 2 - 45.f), ImVec2(windowSize.x / 2 + 5.f, 40.f), "Health");

            ImGui::Checkbox("Godmode", &godmode);

            if (ImGui::Button("Suicide")) {
				ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 0, 0, 0);
            }

            EndChild();

            DrawChild(ImVec2(windowSize.x / 2 - 5.f, 200.f), ImVec2(windowSize.x / 2 + 5.f, windowSize.y / 2 + 5.f), "Invisible");

            

            EndChild();

            DrawChild(ImVec2(windowSize.x / 2 - 5.f, 135.f), ImVec2(windowSize.x / 2 + 5.f, windowSize.y / 2 + 205.f), "Multiplier");

            

            EndChild();

            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Cosmetic")) {


            ImGui::EndTabItem();
        }

        ImGui::EndTabBar();
    }
}
