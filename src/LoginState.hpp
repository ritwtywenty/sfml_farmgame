#include "EngineNodes.hpp"
#include <imgui/imgui.h>
#include <string.h>

class LoginState : public EngineNodes::EngineNode
{
    char email_buffer[50];
    char pass_buffer[50];

public:
    LoginState();
    void draw(sf::RenderWindow &window);
};
