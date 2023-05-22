#include "BinarySearchTree.hpp"
#include <queue>
//Construtor
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

//Helpers
BSTNode* BinarySearchTree::insertHelper(BSTNode* node, int value) {
    if (node == nullptr)
        return new BSTNode(value);

    if (value < node->data)
        node->left = insertHelper(node->left, value);
    else
        node->right = insertHelper(node->right, value);

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

std::string BinarySearchTree::preOrdemHelper(BSTNode* node) {
    std::string traversal;

    if (node == nullptr)
        return traversal;

    traversal += std::to_string(node->data) + " ";
    traversal += preOrdemHelper(node->left);
    traversal += preOrdemHelper(node->right);

    return traversal;
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

bool BinarySearchTree::ehCheiaHelper(BSTNode* node) {
    // If the node is empty, it is a full tree
    if (node == nullptr) {
        return true;
    }

    // If both children are empty, it is a full tree
    if (node->left == nullptr && node->right == nullptr) {
        return true;
    }

    // If both children are present, recursively check if the left and right subtrees are full trees
    if (node->left != nullptr && node->right != nullptr) {
        return ehCheiaHelper(node->left) && ehCheiaHelper(node->right);
    }

    // If only one child is present, it is not a full tree
    return false;
}

bool BinarySearchTree::ehCompletaHelper(BSTNode* node, int index, int depth) {
    if (node == nullptr)
        return (true);
 
    if (index >= depth)
        return (false);

    return (ehCompletaHelper(node->left, 2*index + 1, depth) &&
            ehCompletaHelper(node->right, 2*index + 2, depth));
    }

void BinarySearchTree::imprimeArvore1Helper(BSTNode* node, std::string prefix) {
    if (node == nullptr)
        return;

    if (prefix.empty()) {
        std::cout << node->data << "----------------------------------" << std::endl;
    } else {
        std::cout << prefix << node->data << "----------------------------" << std::endl;
    }

    imprimeArvore1Helper(node->left, prefix + "\t\t");
    imprimeArvore1Helper(node->right, prefix + "\t\t");
}


void BinarySearchTree::imprimeArvore2Helper(BSTNode* node, int depth) {
    if (node == nullptr)
        return;

    std::cout << "(" << node->data << " ";
    imprimeArvore2Helper(node->left,depth);
    std::cout << " ";
    imprimeArvore2Helper(node->right,depth);
    std::cout << ")";
}

BSTNode* BinarySearchTree::findMinNode(BSTNode* node) {
    BSTNode* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

int BinarySearchTree::countNodes(BSTNode* root) {
    if (root == nullptr)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

//Funções públicas
void BinarySearchTree::insert(int value) {
    root = insertHelper(root, value);
}

std::string BinarySearchTree::pre_ordem() {
    return preOrdemHelper(root);
}

void BinarySearchTree::remove(int value) {
    root = removeHelper(root, value);
}

bool BinarySearchTree::search(int value) {
    BSTNode* foundNode = searchHelper(root, value);
    return foundNode != nullptr;
}

bool BinarySearchTree::ehCheia() {
    return ehCheiaHelper(root);
}

bool BinarySearchTree::ehCompleta() {
    int number_nodes = countNodes(root);
    return ehCompletaHelper(root, 0, number_nodes);
}

void BinarySearchTree::imprimeArvore (int s) {
    int number_nodes = countNodes(root);

    if(s == 1)
        imprimeArvore1Helper(root,"");
    else if (s == 2)
        imprimeArvore2Helper(root,number_nodes);
    else
        std::cout << "Erro: Formato Inválido!";
    std::cout << std::endl;
}
void BinarySearchTree::OrdemT(BSTNode* root, int &cont, int n, int &enesimo){
    if (root == nullptr) {
        return;
    }
    // Percorre a subárvore direita
    OrdemT(root->right, cont, n, enesimo);
    // Verifica se o elemento atual é o n-ésimo elemento
    cont++;
    if (cont == n) {
        enesimo = root->data;
        return;
    }
    // Percorre a subárvore esquerda
    OrdemT(root->left, cont, n, enesimo);

}
int BinarySearchTree::enesimoElemento (BSTNode* root,int n){
    int cont = 0;  // Contador para rastrear a posição atual no percurso em ordem
    int enesimo = 0; // Variável para armazenar o resultado


    // Realiza o percurso em ordem e atualiza o resultado quando encontrar o n-ésimo elemento
    OrdemT(root, cont, n, enesimo);


    return enesimo;
}
