#include "BinarySearchTree.hpp"

int main()
{
    BinarySearchTree bst;

    // Insere os nodes na ABB
    bst.insert(32);
    bst.insert(13);
    bst.insert(41);
    bst.insert(5);
    bst.insert(20);
    bst.insert(36);
    bst.insert(60);

    // Sequência de visitação da ABB em pré-ordem.
    std::string result = bst.pre_ordem();
    std::cout << "Sequencia de Visitação : " << result << std::endl;

    bst.remove(7);

    //Sequência de visitação da ABB em pré-ordem.
    std::string traversalResult = bst.pre_ordem();
    std::cout << "Sequencia de Visitação : " << traversalResult << std::endl;

    if(bst.search(20))
        std::cout << "20 Encontrado" << std::endl;
    else
        std::cout << "20 NÃO Encontrado" << std::endl;

    if(bst.ehCheia())
        std::cout << "É BST CHEIA" << std::endl;
    else
        std::cout << "NÃO É BST CHEIA" << std::endl;
    
    if(bst.ehCompleta())
        std::cout << "É BST COMPLETA" << std::endl;
    else
        std::cout << "NÃO É BST COMPLETA" << std::endl;

    bst.imprimeArvore(1);

    int n = 4;
    int enesimo = bst.enesimoElemento(n);
    std::cout << "O " << n << "º elemento do percurso em ordem é: " << enesimo << std::endl;
    return 0;
}
