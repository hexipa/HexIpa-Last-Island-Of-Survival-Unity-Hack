#pragma GCC diagnostic ignored "-Wunused-function"

void centredElement(int element, const char* text, float height = 0){

ImVec2 window_size = ImGui::GetWindowSize();
ImVec2 window_pos = ImGui::GetWindowPos();

if(element == 0){
ImVec2 text_size = ImGui::CalcTextSize(text);

// Рассчитываем позицию для центрирования
ImVec2 centered_pos = ImVec2(
    (window_pos.x + (window_size.x - text_size.x) * 0.5f), // Центр по X
    (window_pos.y + (window_size.y - text_size.y - height) * 0.5f)  // Центр по Y
);

// Передвигаем курсор ImGui в центр
ImGui::SetCursorPos(centered_pos);

ImGui::Text("%s", text);
}
if(element == 1){
ImVec2 text_size = ImGui::CalcTextSize(text);

// Рассчитываем позицию для центрирования
ImVec2 centered_pos = ImVec2(
    (window_pos.x + (window_size.x - text_size.x) * 0.5f), // Центр по X
    (window_pos.y + (window_size.y - text_size.y - height) * 0.5f)  // Центр по Y
);

// Передвигаем курсор ImGui в центр
ImGui::SetCursorPos(centered_pos);

ImGui::Button(text);
}
}

static void HelpMarker(const char* desc)
{
    ImGui::TextDisabled("(?)");
    if (ImGui::BeginItemTooltip())
    {
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}