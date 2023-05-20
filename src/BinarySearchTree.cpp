#include "BinarySearchTree.hpp"

//Construtor
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

//Helpers
BSTNode* BinarySearchTree::insertHelper(BSTNode* node, int value) {
    if (node == nullptr) {
        return new BSTNode(value);
    }

    if (value < node->data) {
        node->left = insertHelper(node->left, value);
    } else {
        node->right = insertHelper(node->right, value);
    }

    return node;
}

BSTNode* BinarySearchTree::removeHelper(BSTNode* node, int value) {
    if (node == nullptr) {
        return nullptr;
    }

    if (value < node->data) {
        node->left = removeHelper(node->left, value);
    } else if (value > node->data) {
        node->right = removeHelper(node->right, value);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        } else if (node->left == nullptr) {
            BSTNode* temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) {
            BSTNode* temp = node;
            node = node->left;
            delete temp;
        } else {
            BSTNode* minRight = findMinNode(node->right);
            node->data = minRight->data;
            node->right = removeHelper(node->right, minRight->data);
        }
    }

    return node;
}

void BinarySearchTree::preOrdemHelper(BSTNode* node, std::string& result) {
    if (node != nullptr) {
        preOrdemHelper(node->left, result);
        result += std::to_string(node->data) + " ";
        preOrdemHelper(node->right, result);
    }
}

BSTNode* BinarySearchTree::searchHelper(BSTNode* node, int value) {
    if (node == nullptr || node->data == value) {
        return node;
    }

    if (value < node->data) {
        return searchHelper(node->left, value);
    } else {
        return searchHelper(node->right, value);
    }
}

BSTNode* BinarySearchTree::findMinNode(BSTNode* node) {
    BSTNode* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

//Funções públicas
void BinarySearchTree::insert(int value) {
    root = insertHelper(root, value);
}

std::string BinarySearchTree::pre_ordem() {
    std::string result;
    preOrdemHelper(root, result);
    return result;
}

void BinarySearchTree::remove(int value) {
    root = removeHelper(root, value);
}

bool BinarySearchTree::search(int value) {
    BSTNode* foundNode = searchHelper(root, value);
    return foundNode != nullptr;
}