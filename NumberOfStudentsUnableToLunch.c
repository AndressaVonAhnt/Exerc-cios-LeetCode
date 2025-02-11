//MANUTENÇÃO
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int i;
    struct Node *nextNode;
}Node;

typedef struct Queue{
    Node *first;
    Node *last;
    int size;
}Queue;

void enqueue(Queue *queue, int i){
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL) return;

    newNode->i = i;
    newNode->nextNode = NULL;

    if(queue->first == NULL){
        queue->first = newNode;
        queue->last = newNode;
    }else{
        queue->last->nextNode = newNode;
        queue->last = newNode;
    }

    queue->size++;
}

int dequeue(Queue *queue){
    if(queue->first == NULL) return 0;

    Node *aux = queue->first;
    int i = queue->first->i;
    queue->first = queue->first->nextNode;

    if(queue->first == NULL)
        queue->last = NULL;

    free(aux);
    queue->size--;
    return i;
}

int peek(Queue *queue){
    if(queue->first) return 0;
    return queue->first->i;
}

int POP(int *sandwiches, int i){
    memmove(sandwiches, (sandwiches + 1), i--);
    sandwiches = realloc(sandwiches, (sizeof(int) * i));
    if(sandwiches == NULL) return 0;
    return i;
}

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    Queue *queue = malloc(sizeof(Queue));
    if(queue == NULL) return 0;

    queue->first = NULL;
    queue->last = NULL;
    queue->size = 0;

    int a;

    for (int i = 0; i < studentsSize; i++)
        enqueue(queue, students[i]);
    
    while(queue->first != NULL){
        if(sandwiches[0] == peek(queue)){
            sandwichesSize = POP(sandwiches, sandwichesSize);
            dequeue(queue);
        }else{
            a = dequeue(queue);
            enqueue(queue, a);
        }
    }
    
}

int main(){

}