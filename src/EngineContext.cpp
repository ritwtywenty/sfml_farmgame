#include "EngineContext.hpp"
using namespace std;
using namespace EngineNodes;
sf::RenderWindow *EngineContext::window;
stack<EngineNode *> EngineContext::gameState;
EngineFeatures::_V2f EngineContext::screeSize;
vector<EngineNode *> EngineContext::publicStatesData;
vector<EngineNode *> EngineContext::alwaysUpdate;
Font EngineContext::font;
int EngineContext::fps;
