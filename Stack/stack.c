#include <stdio.h>
#include <stdlib.h>

#include "stack.h"


struct stack* initStack(void){
    
	struct stack* s = (struct stack*)malloc(sizeof(*s));
    
	if (s != NULL){
    	s->top = NULL;
    	return s;
    }
	return NULL;
}


int clearStack(struct stack * s){

	struct node* temp;
		
	while(s->top != NULL){	
		temp = s->top;
		s->top = s->top->next;
		free(temp);
	}		
	free(s);
	return 0;
}


int push(struct stack* s, int d){

	struct node* n = (struct node*)malloc(sizeof(*n));
	if (n != NULL){
		n->data = d;
    	n->next = s->top;
    	s->top = n;
		return 0;
    }
	return -1;
}


int pop(struct stack* s){

	if(s->top == NULL){
		printf("\nThe stack is empty\n");
    	return -1;
    }
    
	int data;
    data = s->top->data;
    
   	struct node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return data;
}


int peek(struct stack* s){

	if(s->top == NULL){
    	printf("\nThe stack is empty\n");
    	return -1;
    }	
	int data;
    data = s->top->data;
    return data;
}


int isEmpty(struct stack* s){

	return (s->top == NULL);
}


int isNotNull(struct stack* s){
	return (s != NULL);
}


int stackSize(struct stack* s){
	
	int size = 0;
	struct node* temp = s->top;

	while(temp != NULL){
		temp = temp->next;
		size++;
	}
	return size;
}
