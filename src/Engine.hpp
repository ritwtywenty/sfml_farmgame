#pragma once

#include <SFML/Graphics.hpp>
#include <imgui/imgui.h>
#include <imgui/imgui-rendering-SFML.h>
#include <imgui/imgui-events-SFML.h>

#include "EngineNodes.hpp"
#include "EngineContext.hpp"
#include "Features.hpp"

using namespace sf;
using namespace EngineNodes;

/*
        Sempre vai atualizar o estado de jogo do topo,
    todo objeto marcado com runnable = false dentro do loop de jogo,
    será removido do vetor atual e deletado com comando delete.
*/
bool EngineNodeCmp(EngineNodes::EngineNode*, EngineNodes::EngineNode*);
class GameEngine
{
private:
    RenderWindow window;
    Clock clock;
    Time time;
    Event _event;
    float delta;
public:
    GameEngine();
private:
    void update(Time delta);
    void draw(RenderWindow &window);
    void event(Event &event);
public:
    void mainloop();
};
