#include "tree.hpp"

BST* getNewNode(int data){
    BST* newNode = new BST;
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

BST* insert(BST* root, int data){
    if(root == NULL){// empty tree
        root = getNewNode(data);
    }else if(data <= root -> data){
        root -> left = insert(root -> left,data);
    }else{
        root -> right = insert(root -> right,data);
    } 
    return root;
}

bool search(BST* root,int data){
    if(root == NULL) return false;
    else if(root -> data == data) return true;
    else if(data <= root ->data) return search(root -> left,data);
    else return search(root -> right,data);
}