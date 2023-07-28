#ifndef LINKED_LIST_H
#define LINKED_LIST_H




struct node{                                                               /*Node struct for the linked list*/
    
    int data;
    struct node* next;
};


struct linkedList{                                                         /*The actual linked list structure*/                                                      

	struct node* head;
};


/*API*/

extern struct linkedList* initList(void);							        /*Initializes a linked list*/
extern int deleteList(struct node** head_ref);						        /*Delete a linked list*/
extern void insertAtHead(struct node** head_ref, int data); 				/*Insert a node at the beginning*/
extern int insertBehind(struct node** prev_node, int data); 				/*Insert a node after another node*/
extern void insertAtTail(struct node** head_ref, int data); 				/*Insert node at the end*/
extern int removeNode(struct node** head_ref, int nodenum);			        /*Remove node from the list*/ 
extern void printLinkedListData(struct node** node); 					    /*Traverse the linked list starting from the node given and print the data of every node*/
extern int returnSize(struct node** node);						            /*Traverse the linked list starting from the node given and print the size remaining*/
#endif
