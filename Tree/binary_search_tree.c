#include <stdlib.h>
#include <stdio.h>

#include "binary_search_tree.h"



struct treenode* createTreenode(int value){
    struct treenode* node = (struct treenode*)malloc(sizeof(*node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void freeNodes(struct treenode* root){
    if(root != NULL){
        freeNodes(root->left);
        freeNodes(root->right);
        free(root);
    }
}

void insertTreenode(struct treenode** root, int value){
    if ((*root) == NULL){
        *root = createTreenode(value);
    }
    else if (value < (*root)->value){
        insertTreenode(&((*root)->left), value);
    }
    else    {
        insertTreenode(&((*root)->right), value);
    }
}

int deleteTreenode(struct treenode** root, int value){

    if((*root) == NULL){
        return -1;
    }
    if((*root)->value < value){
        deleteTreenode(&((*root)->right), value);
    }
    else if((*root)->value > value){
        deleteTreenode(&((*root)->left), value);
    }
    else{
        if((*root)->left == NULL && (*root)->right == NULL){        /*Leaf node case*/
            free(*root);
            (*root) = NULL;
        }
        else if((*root)->left == NULL){                             /*Only a right child case*/
            struct treenode* temp = (*root);
            (*root) = (*root)->right;
            free(temp);
        }
        else if((*root)->right == NULL){                            /*Only a left child case*/
            struct treenode* temp = (*root);
            (*root) = (*root)->left;
            free(temp);
        }
        else{                                                       /*Two childs case*/
            struct treenode* successor = (*root)->right;
            while(successor->left != NULL){
                successor = successor->left;
            }
            (*root)->value = successor->value;
            deleteTreenode(&((*root)->right), successor->value);
        }
    }
    return 0;
}

void traverse(struct treenode* root){
    if(root != NULL){
        traverse(root->left);
        printf("%d ",root->value);
        traverse(root->right);
    }
}