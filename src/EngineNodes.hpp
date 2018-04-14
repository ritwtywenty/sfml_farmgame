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
        _NODE, // Node básico
        _BASE_OBJECT, // Node de objeto básico
    };
    /*
        Node base para criar qualquer objeto de jogo.
        Recebe tudo que é necessário para desenhar, atualizar e respoder a eventos.
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
        // Caso falso, o moto, removerá junto a memória.
        bool isRunning();
    protected:
        // Tipo de objeto
        int type;
        // Valor para organização do vetor de execução
        int depth;
        bool running;
    public:
        typedef std::vector<EngineNode *> EngineNodeVector;
        typedef std::vector<EngineNode *>::iterator VectorNode;
    };
}


