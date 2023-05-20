#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP
#include <iostream>
#include <string>
#include "BSTNode.hpp"

class BinarySearchTree {
private:
    BSTNode* root;
    BSTNode* insertHelper(BSTNode* node, int value);
    void preOrdemHelper(BSTNode* node, std::string& result);
    BSTNode* removeHelper(BSTNode* node, int value);
    BSTNode* findMinNode(BSTNode* node);
    BSTNode* searchHelper(BSTNode* node, int value);

public:
    BinarySearchTree();
    void insert(int value);
    std::string  pre_ordem();
    void remove(int value);
    bool search(int value);
};

#endif
