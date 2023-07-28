
#define MAX_SIZE 100               /*Max size of the queue*/

extern int queue[MAX_SIZE];        /*Fixed size array used to implement the queue*/

/*API*/

extern int isEmpty();              /*Check if the queue is empty*/
extern int isFull();               /*Check if the queue is full*/
extern void enqueue(int value);    /*Add an element to the end of the queue*/
extern int dequeue();              /*Remove an element from the front of the queue and return it*/
extern int peek();                 /*Return the element at the front of the queue without removing it*/