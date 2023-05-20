#include <iostream>
#include<stdlib.h>
#include "tree.hpp"

using namespace std;

int main() {
    BST* root = NULL;
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,25);
    root = insert(root,8);
    root = insert(root,12);
    int num;
    printf("Digite um número para buscar:\n");
    scanf("%d",&num);
    if(search(root,num)==1)
    {
        printf("Número encontrado");
    }
    else
    {
        printf("Número não encontrado");
    }
    system("clear");
} 