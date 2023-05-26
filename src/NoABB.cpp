#include "NoABB.hpp"

NoABB::NoABB(int valor) {
    dado = valor; //<! Guarda o valor do número no nó 
    esquerda = nullptr; //<! Guarda o nó filho esquerdo
    direita = nullptr; //<! Guarda o nó filho direito
}