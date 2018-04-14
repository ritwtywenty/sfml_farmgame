#include "Gui.hpp"
using namespace sf;
using namespace Gui;
void Label::make(float _x, float _y, string str)
{
    text.setFont(EngineContext::font);
    text.setString(str);
    setPosition(_x, _y);
    depth = 2000;
}
Label::Label()
{
    make(0, 0, "Label");
}
Label::Label(float x, float y, string str)
{
    make(x, y, str);
}
void Label::draw(RenderWindow &window)
{
    window.draw(text);
}
void Label::setText(string str)
{
    text.setString(str);
}
void Label::setPosition(float _x, float _y)
{
    position.x = _x;
    position.y = _y;
    text.setPosition(position.x, position.y);
}
void Label::setCharacterSize(unsigned int size)
{
    text.setCharacterSize(size);
}
void Button::make(float x, float y, float w, float h, string str)
{
    depth = 2000;
    setPosition(x, y);
    setSize(w, h);
    label.setText(str);
    label.setCharacterSize(12);
    fill.r = 100;
    fill.g = 100;
    fill.b = 100;
    fill.a = 255;
    fillActived.r = 200;
    fillActived.g = 200;
    fillActived.b = 200;
    fillActived.a = 255;
    outline.r = 150;
    outline.g = 150;
    outline.b = 150;
    outline.a = 255;
    body.setOutlineColor(outline);
    body.setOutlineThickness(1);
    body.setFillColor(fill);
}
Button::Button()
{
    make(0, 0, 100, 50, "Button");
}
Button::Button(float x, float y, float w, float h, string str)
{
    make(x, y, w, h, str);
}
void Button::setPosition(float _x, float _y)
{
    position.x = _x;
    position.y = _y;
    label.setPosition(_x, _y);
    body.setPosition(_x, _y);
    photo.setPosition(_x, _y);
}
void Button::setSize(float _x, float _y)
{
    size.x = _x;
    size.y = _y;
    body.setSize(Vector2f(_x, _y));
}
void Button::draw(RenderWindow &window)
{
    window.draw(body);
    window.draw(photo);
    label.draw(window);
}
bool Button::callback(Event &event)
{
    Vector2f mouse = EngineContext::window->mapPixelToCoords(Mouse::getPosition(*EngineContext::window), EngineContext::window->getView());
    if(event.type == Event::MouseMoved)
        if(Physics::pointOverArea(position.x, position.y, size.x, size.y, mouse.x, mouse.y))
            body.setFillColor(fillActived);
        else body.setFillColor(fill);
    else if(event.type == Event::MouseButtonReleased)
        if(event.mouseButton.button == 0)
            if(Physics::pointOverArea(position.x, position.y, size.x, size.y, mouse.x, mouse.y))
                return true;
    return false;
}

void ButtonAnim::make()
{
    fator = size.x;
    inc = fator * 0.3;
    fator = inc * 3;
    offset = 0;
    anim = false;
}

ButtonAnim::ButtonAnim()
    : Button()
{
    make();
}
ButtonAnim::ButtonAnim(float x, float y, float w, float h, string str)
    : Button(x, y, w, h, str)
{
    make();
}
void ButtonAnim::update(Time delta)
{
    if(anim)
    {
        if(offset < fator)
        {
            offset += inc;
            setPosition(position.x - offset * delta.asSeconds(), position.y - offset * delta.asSeconds());
            setSize(size.x + offset * delta.asSeconds() * 2, size.y + offset * delta.asSeconds() * 2);
        } //else offset = fator;
    }
    else
    {
        if(offset > 0)
        {
            setPosition(position.x + offset * delta.asSeconds(), position.y + offset * delta.asSeconds());
            setSize(size.x - offset * delta.asSeconds() * 2, size.y - offset * delta.asSeconds() * 2);
            offset -= inc;
        } //else offset = 0;
    }
}
bool ButtonAnim::callback(Event &event)
{
    Vector2f mouse = EngineContext::window->mapPixelToCoords(Mouse::getPosition(*EngineContext::window), EngineContext::window->getView());
    if(event.type == Event::MouseMoved)
        if(Physics::pointOverArea(position.x, position.y, size.x, size.y, mouse.x, mouse.y))
        {
            body.setFillColor(fillActived);
            anim = true;
        }
        else
        {
            body.setFillColor(fill);
            anim = false;
        }
    else if(event.type == Event::MouseButtonReleased)
        if(event.mouseButton.button == 0)
            if(Physics::pointOverArea(position.x, position.y, size.x, size.y, mouse.x, mouse.y))
                return true;
    return false;
}

void ListItem::make()
{
    id = 1;
}

ListItem::ListItem()
 : Button()
{
    make();
}
ListItem::ListItem(string str)
 : Button(0, 0, 1, 1, str)
{
    // o tamanho do item e corrigido através lista
    make();
}

void ListItem::draw(RenderTexture& painel)
{
    painel.draw(body);
    painel.draw(photo);
    painel.draw(label.text);
}

bool ListItem::callback(Event event, Vector2f map, int viewOffset)
{
    Vector2f mouse = EngineContext::window->mapPixelToCoords(Mouse::getPosition(*EngineContext::window), EngineContext::window->getView());
    mouse.x -= map.x;
    mouse.y -= map.y - viewOffset;
    if(event.type == Event::MouseMoved)
        if(Physics::pointOverArea(position.x, position.y, size.x, size.y, mouse.x, mouse.y))
            body.setFillColor(fillActived);
        else body.setFillColor(fill);
    else if(event.type == Event::MouseButtonReleased)
        if(event.mouseButton.button == 0)
            if(Physics::pointOverArea(position.x, position.y, size.x, size.y, mouse.x, mouse.y))
                return true;
    return false;
}

void List::make(float x, float y, float w, float h)
{
    background.a = 150;
    border.setFillColor(background);
    setSize(Vector2f(w, h), 5);
    setPosition(x, y);
    border.setFillColor(Color::Black);
    border.setOutlineThickness(1);
    border.setOutlineColor(Color::White);
    auto_id = 1;
    offset = 0;
    rollspeed = 10;
}

void List::setSize(Vector2f size, int itenSize)
{
    painel.create(size.x, size.y);
    view = painel.getView();
    painel.setView(view);
    border.setSize(size);
    emtsize.x = size.x;
    emtsize.y = (size.y/itenSize);
}

void List::setPosition(float x, float y)
{
    border.setPosition(x, y);
    body.setPosition(x, y);
}

List::List(float x, float y, float w, float h)
{
    make(x, y, w, h);
}

List::List()
{
    make(0, 0, 100, 100);
}

void List::draw(RenderWindow &window)
{
    painel.clear(background);
    for(node = elementos.begin(); node < elementos.end(); node++)
    {
        (*node)->draw(painel);
    }
    painel.display();
    window.draw(border);
    body.setTexture(painel.getTexture());
    window.draw(body);
}
int List::callback(Event &event)
{
    Vector2f mouse = EngineContext::window->mapPixelToCoords(Mouse::getPosition(*EngineContext::window), EngineContext::window->getView());
    if(event.MouseButtonPressed || event.MouseButtonReleased)
    {
        if(Physics::pointOverArea(border.getPosition().x, border.getPosition().y, border.getSize().x, border.getSize().y,
                                   mouse.x, mouse.y))
        {
            for(node = elementos.begin(); node < elementos.end(); node++)
            {
                if((*node)->callback(event, body.getPosition(), offset))
                {
                    return (*node)->id;
                }
            }
        }
    }
    if(event.MouseMoved)
    {
        if(Physics::pointOverArea(border.getPosition().x, border.getPosition().y, border.getSize().x, border.getSize().y,
                                   mouse.x, mouse.y))
        {
            for(node = elementos.begin(); node < elementos.end(); node++)
            {
                if((*node)->callback(event, body.getPosition(), offset))
                {
                    return (*node)->id;
                }
            }
        }
    }
    if(event.MouseWheelMoved)
    {
        if(Physics::pointOverArea(border.getPosition().x, border.getPosition().y, border.getSize().x, border.getSize().y,
                                   mouse.x, mouse.y))
        {
            int toy = event.mouseWheel.delta * -rollspeed;
            offset += toy;
            if(offset >= 0 &&
            (offset <= elementos.size() * emtsize.y - border.getSize().y))
            {
                view.move(0, toy);
                painel.setView(view);
            } else offset -= toy;
        }
    }

    return 0;
}
void List::push_back(ListItem *drone)
{
    drone->setPosition(0,emtsize.y * elementos.size());
    drone->setSize(emtsize.x, emtsize.y);
    if(auto_id > 0)
    {
        drone->id = auto_id;
        auto_id ++;
    }
    elementos.push_back(drone);
}
void List::erase(ListItem *)
{

}

void Line::make(float x, float y, float w, float h)
{
    setPositionLeft(x, y);
    setPositionRight(w, h);
}
Line::Line()
{
    make(0, 0, 0, 0);
}
Line::Line(float x, float y, float w, float h)
{
    make(x, y, w, h);
}
void Line::setPositionLeft(float x, float y)
{
    vertex[0].position.x = x;
    vertex[0].position.y = y;
}
Vector2f Line::getPositionLeft()
{
    return vertex[0].position;
}
void Line::setPositionRight(float w, float h)
{
    vertex[1].position.x = w;
    vertex[1].position.y = h;
}
Vector2f Line::getPositionRight()
{
    return vertex[1].position;
}
void Line::draw(RenderWindow &window)
{
    window.draw(vertex, 2, Lines);
}
Color Line::getColor()
{
    return vertex[0].color;
}
void Line::setColor(Color cor)
{
    vertex[0].color = cor;
    vertex[1].color = cor;
}
