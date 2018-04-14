/*
    Dentro do contexto então todas as variáveis globais e todos os nodes.
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
    // Tamanho da resolução da tela.
    static EngineFeatures::_V2f screeSize;
    // Estados de jogo visíveis a todos os objetos.
    static vector<EngineNode *> publicStatesData;
    // Objetos que independentemente do estado, serão atualizados.
    static vector<EngineNode *> alwaysUpdate;
    // Fonte padrão
    static Font font;
    // Taxa de quadros
    static int fps;
};
