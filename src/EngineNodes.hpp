/*
    Classes primitivas para objetos de jogo.
*/
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
namespace EngineNodes
{
    // Tipos de nodo para engine
    enum
    {
        _STATE = 30, // Stado de jogo, como menus.
        _NODE, // Node b�sico
        _BASE_OBJECT, // Node de objeto b�sico
    };
    /*
        Node base para criar qualquer objeto de jogo.
        Recebe tudo que � necess�rio para desenhar, atualizar e respoder a eventos.
    */
    class EngineNode
    {
    public:
        EngineNode();
        virtual ~EngineNode(){}
        virtual void draw(RenderWindow &window);
        virtual void update(Time delta);
        virtual void event(Event &event);
        int getType();
        int getDepth();
        // Caso falso, o moto, remover� junto a mem�ria.
        bool isRunning();
    protected:
        // Tipo de objeto
        int type;
        // Valor para organiza��o do vetor de execu��o
        int depth;
        bool running;
    public:
        typedef std::vector<EngineNode *> EngineNodeVector;
        typedef std::vector<EngineNode *>::iterator VectorNode;
    };
}


