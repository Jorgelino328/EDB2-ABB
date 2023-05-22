#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP
#include <iostream>
#include <string>
#include <limits>
#include "BSTNode.hpp"

class BinarySearchTree {
    private:
        BSTNode* root;
        BSTNode* insertHelper(BSTNode* node, int value);
        std::string preOrdemHelper(BSTNode* node);
        BSTNode* removeHelper(BSTNode* node, int value);
        BSTNode* findMinNode(BSTNode* node);
        BSTNode* searchHelper(BSTNode* node, int value);
        bool ehCheiaHelper(BSTNode* node);
        bool ehCompletaHelper(BSTNode* root, int index, int number_nodes);
        int countNodes(BSTNode* node);
        void imprimeArvore1Helper(BSTNode* root, std::string prefix);
        void imprimeArvore2Helper(BSTNode* root, int number_nodes);

    public:
        BinarySearchTree();
        void insert(int value);
        std::string  pre_ordem();
        void remove(int value);
        bool search(int value);
        bool ehCheia();
        bool ehCompleta();
        void imprimeArvore(int format);
        void OrdemT(BSTNode* root, int &cont, int n, int &enesimo);
        int enesimoElemento(BSTNode* root,int n);

};

#endif
