#pragma once
#include "Features.hpp"
#include "EngineNodes.hpp"
#include "EngineContext.hpp"
#include "Physics.hpp"
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
using namespace std;
namespace Gui
{
    class Label : public EngineNodes::EngineNode
    {
    public:
        void make(float x, float y, string str);
        Text text;
        EngineFeatures::V2f position;
        Label();
        Label(float x, float y, string str);
        virtual void draw(RenderWindow &window);
        void setPosition(float _x, float _y);
        void setCharacterSize(unsigned int size);
        void setText(string str);
    };
    class Button : public EngineNodes::EngineNode
    {
    public:
        Label label;
        RectangleShape body;
        EngineFeatures::V2f position;
        EngineFeatures::V2f size;
        Color fill;
        Color fillActived;
        Color outline;
        Sprite photo;
    private:
        void make(float x, float y, float w, float h, string str);
    public:
        Button();
        Button(float x, float y, float w, float h, string str);
        void setPosition(float _x, float _y);
        void setSize(float _x, float _y);
        virtual void draw(RenderWindow &window);
        virtual bool callback(Event &event);
    };

    class ButtonAnim : public Button
    {
    public:
        float fator;
        float inc;
    protected:
        float offset;
        bool anim;
        void make();
    public:
        ButtonAnim();
        ButtonAnim(float x, float y, float w, float h, string str);
        virtual void update(Time delta);
        virtual bool callback(Event &event);
    };

    class ListItem : public Button
    {
        void make();
    public:
        int id;
        ListItem();
        ListItem(string str);
        virtual void draw(RenderTexture&);
        bool callback(Event event, Vector2f map, int view);
    };

    class List : public EngineNodes::EngineNode
    {

        void make(float x, float y, float w, float h);
    public:
        int offset;
        RectangleShape border;
        RenderTexture painel;
        View view;
        Sprite body;
        typedef vector<ListItem *> VecListit;
        unsigned int auto_id;
        int rollspeed;
        Color background;
    private:
        VecListit::iterator node;
    public:
        VecListit elementos;
        Vector2f emtsize; // Tamanho dos elementos

        List();
        List(float x, float y, float w, float h);
        virtual void draw(RenderWindow &window);
        virtual int callback(Event &event);
        void push_back(ListItem *);
        void erase(ListItem *);
        void setSize(Vector2f size, int itenSize);
        void setPosition(float x, float y);
    };

    class Line : public EngineNodes::EngineNode
    {
        sf::Vertex vertex[2];
        void make(float x, float y, float w, float h);
    public:
        Line();
        Line(float x, float y, float w, float h);
        void setPositionLeft(float x, float y);
        Vector2f getPositionLeft();
        void setPositionRight(float w, float h);
        Vector2f getPositionRight();
        virtual void draw(RenderWindow &window);
        Color getColor();
        void setColor(Color cor);
    };
}
