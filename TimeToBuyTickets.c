#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int num;
    int id;
    struct Node *nextNode;
} Node;

typedef struct{
    Node *head;
    Node *tail;
    int size;
} Queue;

void add(Queue *q, int i, int id){
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL) return;

    newNode->num = i;
    newNode->id = id;
    newNode->nextNode = NULL;

    if(q->size == 0){
        q->head = newNode;
    }else{
        q->tail->nextNode = newNode;
    }
    
    q->tail = newNode;
    q->size++;
}

void delete(Queue *q){
    if(q->size == 0)
        return;
    
    Node *aux = q->head;
    q->head = q->head->nextNode;
    free(aux);
    q->size--;
}

int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int count = 0;

    Queue *q = malloc(sizeof(Queue));
    if(q == NULL) return 0;
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    
    for(int i = 0; i < ticketsSize; i++)
        add(q, tickets[i], i);

    while(q->size > 0){
        Node *current = q->head;
        count++;
        current->num--;

        if (current->num == 0) {
            if (current->id == k) {
                free(q);
                return count;
            }
            delete(q);
        }else{
            add(q, current->num, current->id);
            delete(q);
        }
    }
    free(q);
    return count;
}

int main(){
    int a[4] = {5,1,1,1};
    printf("%d", timeRequiredToBuy(a, 4, 0));
}