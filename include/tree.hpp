#include <iostream>
#include <stdlib.h>
using namespace std;


typedef struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
}BST;


BST* getNewNode(int data);

BST* insert(BST* root, int data);

bool search(BST* root,int data);