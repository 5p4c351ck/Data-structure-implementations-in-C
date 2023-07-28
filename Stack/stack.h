#ifndef STACK_H
#define STACK_H



struct node{                                /*Node for the linked list that will be used to implement the stack*/

    int data;
    struct node* next;
};


struct stack{                               /*The actual stack structure*/

    struct node* top;    
};


/*API*/

extern struct stack* initStack(void);		/*Initialize a stack*/
extern int clearStack(struct stack * s);	/*Delete stack*/
extern int push(struct stack* s, int d);	/*Push an element in the stack*/
extern int pop(struct stack* s);		    /*Pop an element from the stack and return its value*/
extern int peek(struct stack* s);		    /*Like pop but doesnt remove the element*/
extern int isEmpty(struct stack* s);		/*Checks if the stack is empty*/
extern int isNotNull(struct stack* s);      /*Checks if the stack is NULL*/
extern int stackSize(struct stack* s);		/*Returns the size of the stack*/

#endif
