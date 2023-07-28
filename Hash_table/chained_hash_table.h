#ifndef CHAINED_HASH_TABLE_H
#define CHAINED_HAST_TABLE_H

#include <stdint.h>

#define TABLE_SIZE 1000

struct hashNode {

    char* key;
    
    char* type;
    union {
	void* val;
	uint64_t u;
	int64_t s;
	double d;
    }data;
    
    struct hashNode* next;
};



/*API*/

extern struct hashNode** initializeTable(void);                                                         /*Initializes the hashtable*/
extern void deleteTable(struct hashNode** hashTable);                                                   /*Frees the hashtable*/
extern void insert(struct hashNode** hashTable, const char* key, void* value, const char* t);           /*Inserts a node, types include "uint" "sint" "float"*/
extern void removeKeys(struct hashNode** hashTable, const char* key);                                   /*Removes keys*/
extern void printFirst(struct hashNode** hashTable, const char* key);                                   /*Prints the first node*/
extern void printLast(struct hashNode** hashTable, const char* key);                                    /*Prints the last  node*/
extern int contains(struct hashNode** hashTable, const char* key);                                      /*Checks if a node with that key exists*/

#endif 
