#include <stdio.h>
#include <stdlib.h>

#include "undirected_graph.h"

static struct node* createNode(int vert){

    struct node* newnode = (struct node*)malloc(sizeof(*newnode));
    newnode->vert = vert;
    newnode->next = NULL;
    return newnode;
}


struct graph* createGraph(int vertices){

    struct graph* newgraph = (struct graph*)malloc(sizeof(*newgraph));
    newgraph->vertNum = vertices;
    newgraph->edgesNum = 0;
    newgraph->adjList = malloc(sizeof(struct node*) * vertices);
    int i;
    for (i = 0; i < vertices; i++){
        newgraph->adjList[i] = NULL;
    }
    return newgraph;
}

int freeGraph(struct graph* graph){

    if (graph == NULL){
        return -1;
    }

    for (unsigned int i = 0; i < graph->vertNum; i++){
        
        while(graph->adjList[i] != NULL){

            struct node* temp = graph->adjList[i];
            graph->adjList[i] = graph->adjList[i]->next;
            free(temp);
        }
    }
    free(graph->adjList);
    free(graph);
    return 0;
}


int hasEdge(struct graph* graph, int src, int dest){

    if(src < 0 || src >= graph->vertNum){
        return -1;
    }

    struct node* nodetocheck = graph->adjList[src];
    while(nodetocheck != NULL){
        if(nodetocheck->vert == dest){
            return 1;
        }
        nodetocheck = nodetocheck->next;
    }
    return 0;
}

void addEdge(struct graph* graph, int src, int dest){

    if(hasEdge(graph, src, dest)){
        printf("Edge (%d, %d) already exists.\n", src, dest);
        return;
    }
    
    if(src < 0 || src >= graph->vertNum){
        puts("Invalid source vertex.");
        return;
    }
    else if (dest < 0 || dest >= graph->vertNum)
    {
        puts("Invalid destination vertex.");
        return;
    }
    else{
    struct node* newnode = createNode(dest);
    newnode->next = graph->adjList[src];
    graph->adjList[src] = newnode;

    newnode = createNode(src);
    newnode->next = graph->adjList[dest];
    graph->adjList[dest] = newnode;

    graph->edgesNum++;
    }
}


void printGraph(const struct graph* graph){
    int i;
    for (i = 0; i < graph->vertNum; i++){
        struct node* temp = graph->adjList[i];
        printf("Vertex %d:\n", i);
        if(graph->adjList[i] == NULL){
            printf("NULL\n");
        }
        else{
        while(temp){
            printf("%d | ", temp->vert);
            temp = temp->next;
        }
        printf("\n");
        }
    } 
}
