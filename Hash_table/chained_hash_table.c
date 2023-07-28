#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "chained_hash_table.h"

struct hashNode** initializeTable(void){
	
	struct hashNode** hashTable = (struct hashNode**)malloc(sizeof(*hashTable) * TABLE_SIZE);
	
	for (unsigned int i = 0; i < TABLE_SIZE; i++){
	
		hashTable[i] = NULL;
	}
	
	return hashTable;
}


void deleteTable(struct hashNode** hashTable){
	
	if (hashTable != NULL){
		
	struct hashNode* temp;
	
	for (unsigned int i = 0; i < TABLE_SIZE; i++){

		while (hashTable[i] != NULL){
			temp = hashTable[i];
			hashTable[i] = hashTable[i]->next;
			free(temp->key);
			free(temp->type);
			free(temp);
		}
	}
	free(hashTable);
	}
}



static int pseudoHash(const char* key){

    int hashValue = 0;    
    for (int i = 0; i < strlen(key); i++){
        hashValue += key[i];
    }    
    return hashValue % TABLE_SIZE;
}


void insert(struct hashNode** hashTable, const char* key, void* value, const char* t){
    
    int index = pseudoHash(key);
    
    struct hashNode* newNode = (struct hashNode*)malloc(sizeof(*newNode));
    
    newNode->key = strdup(key); 
    newNode->type = strdup(t); 

    if (!strcmp(t, "uint")){
    	
	    newNode->data.u = *((uint64_t*)value);
    }else if (!strcmp(t, "sint")){
    	
	    newNode->data.s = *((int64_t*)value);
    }else if (!strcmp(t, "float")){
    	
	    newNode->data.d = *((double*)value);
    }else{
    	
	    newNode->data.val = value;
    }
    newNode->next = NULL;
    
    if (hashTable[index] == NULL){
        hashTable[index] = newNode;     
    }

    else{
      struct hashNode* temp = hashTable[index];
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void removeKeys(struct hashNode** hashTable, const char* key){
	
	int index = pseudoHash(key);
	struct hashNode* temp;

	while (hashTable[index] != NULL){
                       temp = hashTable[index];
                       hashTable[index] = hashTable[index]->next;
                       free(temp);
                }
}


void printFirst(struct hashNode** hashTable, const char* key){
    
    int index = pseudoHash(key);
    if (hashTable[index] != NULL){

	if (!strcmp(hashTable[index]->type, "uint")){
            printf("%lu\n", hashTable[index]->data.u);

        }else if (!strcmp(hashTable[index]->type, "sint")){
            printf("%ld\n", hashTable[index]->data.s);

        }else if (!strcmp(hashTable[index]->type, "float")){
            printf("%.2f\n", hashTable[index]->data.d);

        }else if (!strcmp(hashTable[index]->type, "char")){
            printf("%s\n", (char *)hashTable[index]->data.val);
        }else{
		return;
	}
    }
	return;
}


void printLast(struct hashNode** hashTable, const char* key){
    
    int index = pseudoHash(key);
    struct hashNode* temp = hashTable[index];    
    
    if (temp != NULL){

    	while (temp->next != NULL){
	    
		temp = temp->next;
	}
    	if (!strcmp(temp->type, "uint")){
            printf("%lu\n", temp->data.u);

        }else if (!strcmp(temp->type, "sint")){
            printf("%ld\n", temp->data.s);

        }else if (!strcmp(temp->type, "float")){
            printf("%f\n", temp->data.d);

        }else if (!strcmp(temp->type, "char")){
            printf("%s\n", (char *)temp->data.val);
        }else{
		return;
	}
    }
	return;
}


int contains(struct hashNode** hashTable, const char* key){

	int index = pseudoHash(key);
	
	if (hashTable[index] != NULL){
		
		return 1;
	}

	return 0;
}
