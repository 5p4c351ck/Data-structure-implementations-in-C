#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

struct linkedList* initList(void){

	struct linkedList* list = (struct linkedList*)malloc(sizeof(*list));
	if (list != NULL){
		list->head = NULL;
		return list;
	}
	return NULL;
}

int deleteList(struct node** head_ref){

	struct node* temp;

	while ((*head_ref)->next != NULL){
		temp = (*head_ref);
		(*head_ref) = (*head_ref)->next;
		free(temp);
	}
	free((*head_ref));
        return 0;
}

void insertAtHead(struct node** head_ref, int data){
    
        struct node* new_node = (struct node*)malloc(sizeof(*new_node));
        new_node->data = data;
        new_node->next = (*head_ref);
        (*head_ref) = new_node;	
}


int insertBehind(struct node** prev_node, int data){
    
        if((*prev_node) == NULL){
        puts("Previous node cant be NULL");
        return -1;
        }
    
        struct node* new_node = (struct node*)malloc(sizeof(*new_node));
        new_node->data = data;
        new_node->next = (*prev_node)->next;
        (*prev_node)->next = new_node;
        return 0;
}


void insertAtTail(struct node** head_ref, int data){

        struct node* new_node = (struct node*)malloc(sizeof(*new_node));
        new_node->data = data;
        new_node->next = NULL;
        
        if((*head_ref) == NULL){
                (*head_ref) = new_node;
                return;
        }
        struct node* last = (*head_ref);
        while(last->next != NULL){
                
                last = last->next;
        }
        last->next = new_node;
}


int removeNode(struct node** head_ref, int nodenum){

        
        if (nodenum <= 0 || (*head_ref) == NULL){
                return -1;
        }
        struct node* current = (*head_ref);
        struct node* prev = NULL;

        if(nodenum == 1){
                (*head_ref) = (*head_ref)->next;
                free(current);
                return 0;
        }
        int count = 0;
        while (current->next != NULL && count < nodenum - 1){
                prev = current;
                current = current->next;
                count++;
        }
        prev->next = current->next;
        free(current);
        return 0;
}


void printLinkedListData(struct node** node){
        
        struct node* temp = (*node);
        printf("\n----------");
        while(temp != NULL){
                
                printf("\n: %d ", temp->data);
                temp = temp->next;
        }
        printf("\n----------\n");
}


int returnSize(struct node** node){
         
         int size = 0;
         struct node* temp = (*node);
         while(temp != NULL){
                
                size++;
                temp = temp->next;
        }
        return size;
}
