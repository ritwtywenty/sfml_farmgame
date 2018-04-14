#include "Physics.hpp"
bool Physics::pointOverArea(float ax, float ay, float aw, float ah, float px, float py)
{
    if(px < ax) return false;
    if(px > ax + aw) return false;
    if(py < ay) return false;
    if(py > ay + ah) return false;
    return true;
}
