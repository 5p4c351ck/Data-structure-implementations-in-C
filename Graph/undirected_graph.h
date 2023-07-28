#ifndef UNDIRECTED_GRAPH_H
#define UNDIRECTED_GRAPH_H


struct node{                                                     /*The node for the linked lists*/
    int vert;
    struct node* next;
};

struct graph{                                                    /*The graph structure*/
    int vertNum;
    int edgesNum;
    struct node** adjList;                                       /*The adjecency list is implemented as an array of linked lists*/
};


/*API*/

extern struct graph* createGraph(int vertices);                    /*Creates a graph and returns a pointer to it */
extern int freeGraph(struct graph* graph);                         /*Frees the graph*/
extern int hasEdge(struct graph* graph, int src, int dest);        /*Check if edge already exists*/
extern void addEdge(struct graph* graph, int src, int dest);       /*Adds an edge between source and destination vertices of the graph*/
extern void printGraph(const struct graph* graph);                 /*Prints the whole graph*/


#endif
