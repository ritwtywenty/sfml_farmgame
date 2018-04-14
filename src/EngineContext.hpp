/*
    Dentro do contexto ent�o todas as vari�veis globais e todos os nodes.
*/
#pragma once
#include <SFML/Config.hpp>
#include "Features.hpp"
#include "EngineNodes.hpp"
#include <stack>
#include <vector>
using namespace std;
using namespace EngineNodes;
class EngineContext
{
public:
    // Janela principal da Engine
    static sf::RenderWindow *window;
    // O estado do topo e atualizado.
    static stack<EngineNode *> gameState;
    // Tamanho da resolu��o da tela.
    static EngineFeatures::_V2f screeSize;
    // Estados de jogo vis�veis a todos os objetos.
    static vector<EngineNode *> publicStatesData;
    // Objetos que independentemente do estado, ser�o atualizados.
    static vector<EngineNode *> alwaysUpdate;
    // Fonte padr�o
    static Font font;
    // Taxa de quadros
    static int fps;
};
