#include "LoginState.hpp"

LoginState::LoginState()
{
    strcpy(email_buffer, "example@ritwty.rib");
}
void LoginState::draw(sf::RenderWindow &window)
{
    ImGui::Begin("Login", nullptr, ImVec2(250, 120), -1.0f, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
    ImGui::Text("Login");
    ImGui::InputText("E-mail", email_buffer, 50, ImGuiInputTextFlags_CharsNoBlank);
    ImGui::InputText("pass", pass_buffer, 50, ImGuiInputTextFlags_Password | ImGuiInputTextFlags_CharsNoBlank);
    if(ImGui::Button("Login"))
    {
        printf("login: %s %s\n", email_buffer, pass_buffer);
    }
    ImGui::End();
}
