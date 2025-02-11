//MANUTENÇÃO
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int i;
    int index;
    struct Node *nextNode;
    struct Node *lastNode;
}Node;

typedef struct Heap{
    Node *first;
    Node *last;
}Heap;

void PUSH(Heap *heap, int a, int index){
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL) return;

    newNode->i = a;
    newNode->index = index;

    if(heap->first == NULL){
        newNode->lastNode = NULL;
        newNode->nextNode = NULL;
        heap->first = newNode;
        heap->last = newNode;
        return;
    }

    for(Node *aux = heap->first; aux != NULL; aux = aux->nextNode){
        if(a < aux->i){
            newNode->lastNode = aux->lastNode;
            aux->lastNode = newNode;
            newNode->nextNode = aux;
            return;
        }
    }
    newNode->lastNode = heap->last;
    heap->last->nextNode = newNode;
    heap->last = newNode;
    newNode->nextNode = NULL;
}

void UPDATE(Heap *heap, int i){
    for (Node *aux = heap->first; aux != NULL; aux = aux->nextNode)
        aux->i = aux->i * i;
    
}

void ORGANIZE(Heap *heap, int *v){
    for (Node *aux = heap->first; aux != NULL; aux = aux->nextNode)
        v[aux->index] = aux->i;
        
}

int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize) {
    Heap *heap = malloc(sizeof(Heap));
    if(heap == NULL) return 0;

    heap->first = NULL;
    heap->last = NULL;

    int *v = malloc(sizeof(int) * numsSize);
    if(v == NULL) return 0;

    returnSize = malloc(sizeof(int));
    if(returnSize == NULL) return 0;
    
    for (int j = 0; j < numsSize; j++){
        PUSH(heap, nums[j], j);
    }

    for (int i = 0; i < k; i++){
        for (Node *aux = heap->first; aux != NULL; aux = aux->nextNode){
            if(i)
                PUSH(heap, aux->i, aux->index);
        }
    }

    *returnSize = numsSize;
    ORGANIZE(heap, v);
    return v;
}

int main(){
    int v[5] = {2,1,3,5,6}, *returnsize, *answer;
    answer = malloc(sizeof(int) * 5);

    answer = getFinalState(v, 5, 5, 2, returnsize);

    for (int i = 0; i < *returnsize; i++)
    {
        printf("%d", answer[i]);
    }
    
}