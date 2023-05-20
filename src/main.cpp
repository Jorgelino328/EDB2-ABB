#include "BinarySearchTree.hpp"

int main()
{
    BinarySearchTree bst;

    // Insere os nodes na ABB
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    
    // Sequência de visitação da ABB em pré-ordem.
    std::string result = bst.pre_ordem();
    std::cout << "Sequencia de Visitação : " << result << std::endl;

    bst.remove(80);

    // Sequência de visitação da ABB em pré-ordem.
    std::string traversalResult = bst.pre_ordem();
    std::cout << "Sequencia de Visitação : " << traversalResult << std::endl;

    if(bst.search(20))
        std::cout << "20 Encontrado" << std::endl;
    else
        std::cout << "20 NÃO Encontrado" << std::endl;
    return 0;
}