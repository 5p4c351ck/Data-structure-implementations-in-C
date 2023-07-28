#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

struct treenode{                                                /*The structure of the tree node*/
    int value;
    struct treenode* right;
    struct treenode* left;
};

/*API*/

extern struct treenode* createTreenode(int value);                /*Create node*/
extern void freeNodes(struct treenode* root);                     /*Frees Tree*/
extern void insertTreenode(struct treenode** root, int value);    /*Insert node at correct location based on it's value*/
extern int deleteTreenode(struct treenode** root, int value);     /*Deletes tree node*/
extern void traverse(struct treenode* root);                      /*Traverse the tree and print the values of the nodes in order*/      

#endif