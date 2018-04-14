#include "Engine.hpp"
using namespace sf;
using namespace std;
using namespace EngineNodes;
bool EngineNodeCmp(EngineNodes::EngineNode* a, EngineNodes::EngineNode* b)
{
    return a->getDepth() < b->getDepth();
}
GameEngine::GameEngine()
{
    if(EngineContext::screeSize.x < 1 ||
       EngineContext::screeSize.x > 12000)
    {
        printf("Resolução horizontal redefinida para 800px\n");
        EngineContext::screeSize.x = 800;
    }
    if(EngineContext::screeSize.y < 1 ||
       EngineContext::screeSize.y > 6000)
    {
        printf("Resolução vertical redefinida para 600px\n");
        EngineContext::screeSize.y = 600;
    }
    if(EngineContext::fps < 1 ||
       EngineContext::fps > 1200)
    {
        printf("Frequência de atualização redefinida para 30 quadros por segundo\n");
        EngineContext::fps = 30;
    }
    EngineContext::font.loadFromFile(EF_default_font);
    window.create(VideoMode(EngineContext::screeSize.x, EngineContext::screeSize.y), "Engine");
    window.setFramerateLimit(EngineContext::fps);
    window.setVerticalSyncEnabled(true);
    EngineContext::window = &window;
}
void GameEngine::update(Time delta)
{
    if(!EngineContext::gameState.empty())
        EngineContext::gameState.top()->update(delta);
    EngineNode::VectorNode node;
    unsigned int nodepos;
    for(nodepos = 0; nodepos < EngineContext::alwaysUpdate.size(); nodepos++)
    {
        node = EngineContext::alwaysUpdate.begin() + nodepos;
        if((*node)->isRunning())
            (*node)->update(delta);
        else
        {
            EngineNode *en = *node;
            EngineContext::alwaysUpdate.erase(node);
            delete en;
        }
    }
    sort(EngineContext::alwaysUpdate.begin(), EngineContext::alwaysUpdate.end(), EngineNodeCmp);
}
void GameEngine::draw(RenderWindow &window)
{
    if(!EngineContext::gameState.empty())
        EngineContext::gameState.top()->draw(window);
    EngineNode::VectorNode node;
    for(node = EngineContext::alwaysUpdate.begin();
    node < EngineContext::alwaysUpdate.end(); node ++)
        (*node)->draw(window);
}
void GameEngine::event(Event &event)
{
    if(!EngineContext::gameState.empty())
        EngineContext::gameState.top()->event(event);
    EngineNode::VectorNode node;
    for(node = EngineContext::alwaysUpdate.begin();
    node < EngineContext::alwaysUpdate.end(); node ++)
        (*node)->event(event);
}
void GameEngine::mainloop()
{
    while(window.isOpen())
    {
        while(window.pollEvent(_event))
        {
            if(_event.type == Event::Closed)
                window.close();
            event(_event);
        }
        update(time);
        window.clear(Color::Black);
        draw(window);
        window.display();
        time = clock.restart();
    }
}
