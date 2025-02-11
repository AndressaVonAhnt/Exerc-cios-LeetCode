/*
    Relative Ranks(506)
    You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.
    The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

    The 1st place athlete's rank is "Gold Medal".
    The 2nd place athlete's rank is "Silver Medal".
    The 3rd place athlete's rank is "Bronze Medal".
    For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
    
    Return an array answer of size n where answer[i] is the rank of the ith athlete.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int score;
    int index;
    struct Node *nextNode;
}Node;

typedef struct Heap{
    struct Node *first;
}Heap;

void PUSH(Heap *heap, int n, int i){
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL)
        return;

    newNode->score = n;
    newNode->index = i;
    newNode->nextNode = NULL;

    if(heap->first == NULL || n > heap->first->score){
        newNode->nextNode = heap->first;
        heap->first = newNode;
        return;
    }

    Node *aux = heap->first;
    while (aux->nextNode != NULL && aux->nextNode->score > n)
        aux = aux->nextNode;
    
    newNode->nextNode = aux->nextNode;
    aux->nextNode = newNode;
}

Node* POP(Heap *heap){
    if(heap->first == NULL)
        return NULL;

    Node *aux = heap->first;
    heap->first = heap->first->nextNode;
    return aux;
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    *returnSize = scoreSize;

    Heap *heap = malloc(sizeof(Heap));
    if(heap == NULL)
        return NULL;
    
    heap->first = NULL;

    for(int i = 0; i < scoreSize; i++)
        PUSH(heap, score[i], i);
    
    char **answer = (char **)malloc(scoreSize * sizeof(char *));
    if(answer == NULL)
        return NULL;

    for(int i = 0; i < scoreSize; i++){
        Node * top = POP(heap);

        answer[top->index] = (char *)malloc(20 * sizeof(char));

        if (i == 0)
            sprintf(answer[top->index], "Gold Medal");
        else if (i == 1)
            sprintf(answer[top->index], "Silver Medal");
        else if (i == 2)
            sprintf(answer[top->index], "Bronze Medal");
        else
            sprintf(answer[top->index], "%d", i + 1);

        free(top);
    }

    free(heap);
    return answer;
}

int main(){
    int scores[] = {10, 3, 8, 9, 4};
    int n = sizeof(scores) / sizeof(scores[0]);
    int returnSize;
    
    char **result = findRelativeRanks(scores, n, &returnSize);

    printf("Ranking dos atletas:\n");
    for (int i = 0; i < returnSize; i++)
        printf("%s\n", result[i]);

    // Liberando a memória alocada
    for (int i = 0; i < returnSize; i++)
        free(result[i]);
    free(result);

}