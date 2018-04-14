#include "src/Engine.hpp"
#include "src/Gui.hpp"

int main()
{
    Gui::Label olaMundo(10, 10, "Olá mundo");
    EngineContext::alwaysUpdate.push_back(&olaMundo);

    GameEngine gameEngine;
    gameEngine.mainloop();
    return 0;
}
