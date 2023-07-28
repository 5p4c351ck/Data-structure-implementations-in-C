#include <stdio.h>

#include "queue.h"

int queue[MAX_SIZE];

static int front = -1;        /*index to the front of the queue*/
static int rear = -1;         /*index to the back of the queue*/


int isEmpty(){

        return (front == -1 && rear == -1);
}

int isFull(){

        return (rear == MAX_SIZE - 1);
}

void enqueue(int value){

        if(isFull()){
                puts("The queue is full.");
                return;
        }
        else if(isEmpty()){
                front = rear = 0;
        }
        else {
                rear++;
        }
        queue[rear] = value;
}

int dequeue(){
    int value;
        if(isEmpty()){
            puts("The queue is empty.");
            return -1;
        }

        value = queue[front];

        if( front == rear){
            front = rear = -1;
        }
        else {
            for (unsigned int i = front; i < rear; i++){
                queue[i] = queue[i + 1]; 
            }
            rear--;
        }
        return value;
}

int peek(){
    int value;
        if(isEmpty()){
            puts("The queue is empty.");
            return -1;
        }
    value = queue[front];
    return value;
}