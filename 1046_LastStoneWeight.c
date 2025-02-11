/*
    Last Stone Weight (1046)
    You are given an array of integers stones where stones[i] is the weight of the ith stone.
    We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:
    If x == y, both stones are destroyed, and
    If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
    At the end of the game, there is at most one stone left.
    Return the weight of the last remaining stone. If there are no stones left, return 0.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int i;
    struct Node *nextNode;
}Node;

typedef struct {
    Node *first;
}Heap;

void PUSH(Heap *heap, int i){
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL) return;

    newNode->i = i; 
    newNode->nextNode = NULL;

    if(heap->first == NULL || i > heap->first->i){
        newNode->nextNode = heap->first;
        heap->first = newNode;
        return;
    } 

    Node* aux = heap->first;
    while(aux->nextNode != NULL && aux->nextNode->i > i)
        aux = aux->nextNode;

    newNode->nextNode = aux->nextNode;
    aux->nextNode = newNode;  
}

int POP(Heap *heap){
    if(heap->first == NULL) return 0;

    Node *aux = heap->first;
    int i = heap->first->i;

    heap->first = heap->first->nextNode;
    free(aux);
    return i;
}

int Calculate(Heap *heap, int y, int x){
    if(x != y){
        y = y - x;
        PUSH(heap, y);
        return y;
    }
    return 0;
}

int lastStoneWeight(int* stones, int stonesSize) {
    int i, j;
    Heap *heap = malloc(sizeof(Heap));
    if(heap == NULL) return 0;

    heap->first = NULL;
    
    for (int i = 0; i < stonesSize; i++)
        PUSH(heap, stones[i]);

    while(heap->first != NULL && heap->first->nextNode != NULL) {
        i = POP(heap);
        j = POP(heap);
        j = Calculate(heap, i, j);
    }

    int result = 0;
    if(heap->first != NULL) 
        result = heap->first->i;  

    free(heap);

    return result;
}

int main(){
    int i[6] = {2,7,4,1,8,1};
    printf("%d", lastStoneWeight(i, 6));
}