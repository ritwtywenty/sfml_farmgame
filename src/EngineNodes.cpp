#include "EngineNodes.hpp"
using namespace sf;
EngineNodes::EngineNode::EngineNode()
    : type(_NODE), running(true), depth(1000){}
void EngineNodes::EngineNode::draw(RenderWindow &window){}
void EngineNodes::EngineNode::update(Time delta){}
void EngineNodes::EngineNode::event(Event &event){}
int EngineNodes::EngineNode::getType()
{
    return type;
}
bool EngineNodes::EngineNode::isRunning()
{
    return running;
}
int EngineNodes::EngineNode::getDepth()
{
    return depth;
}


