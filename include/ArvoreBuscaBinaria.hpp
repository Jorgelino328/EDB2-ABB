#ifndef ARVORE_BUSCA_BINARIA_HPP
#define ARVORE_BUSCA_BINARIA_HPP
#include <iostream>
#include <string>
#include <limits>
#include <queue>
#include <fstream>
#include <sstream>

#include "NoABB.hpp"

class ArvoreBuscaBinaria {
    private:
        NoABB* raiz;
        NoABB* inserirHelper(NoABB* no, int valor);
        std::string preOrdemHelper(NoABB* no);
        NoABB* removerHelper(NoABB* no, int valor);
        NoABB* minNo(NoABB* no);
        NoABB* buscarHelper(NoABB* no, int valor);
        bool ehCheiaHelper(NoABB* no);
        bool ehCompletaHelper(NoABB* raiz, int index, int numeroNos);
        int contarNos(NoABB* no);
        void imprimeArvore1Helper(NoABB* raiz, std::string prefixo);
        void imprimeArvore2Helper(NoABB* raiz, int numeroNos);
        void ordemNes(NoABB* raiz, int &cont, int n, int &enesimo);
        bool ordemPos(NoABB* raiz, int &cont, int x);
        double media (NoABB* raiz);       

    public:
        ArvoreBuscaBinaria();
        void lerArquivos(std::string arquivo1, std::string arquivo2);
        void inserir(int valor);
        std::string  pre_ordem();
        void remover(int valor);
        bool buscar(int valor);
        bool ehCheia();
        bool ehCompleta();
        void imprimeArvore(int s);
        int enesimoElemento(int n);
        int posicao (int x);  
        int mediana ();
        double media (int x);     

};

#endif
