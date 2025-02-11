/*
    Minimum String Length after removing substrings (2696)
    You are given a string s consisting only of uppercase English letters.
    You can apply some operations to this string where, in one operation, you can remove any occurrence of one of the substrings "AB" or "CD" from s.
    Return the minimum possible length of the resulting string that you can obtain.
    Note that the string concatenates after removing the substring and could produce new "AB" or "CD" substrings.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    char c;
    struct Node *nextNode;
    struct Node *lastNode;
}Node;

typedef struct Stack{
    Node *first;
    Node *last;
    int size;
}Stack;

void PUSH(Stack *stack, char c){
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL) return;

    stack->size++;
    newNode->c = c;
    newNode->nextNode = NULL;
    newNode->lastNode = NULL;

    if(stack->first == NULL){
        stack->first = newNode;
        stack->last = newNode;
        return;
    }

    stack->last->nextNode = newNode;
    newNode->lastNode = stack->last;
    stack->last = newNode;
    
}

void POP(Stack *stack){
    if(stack->first == NULL) return; // empty stack

    Node *aux = stack->last;

    stack->size--;
    stack->last = stack->last->lastNode;

    if(stack->size > 0)
        stack->last->nextNode = NULL;
    else
        stack->first = NULL;
        
    free(aux);
}

bool CHECK(Stack *stack){
    if(stack->size < 2) return 0;

    if((stack->last->c == 'B' && stack->last->lastNode->c == 'A') || (stack->last->c == 'D' && stack->last->lastNode->c == 'C')){
        POP(stack);
        POP(stack);
        return 1;
    }
    return 0;
}

int minLength(char* s) {
    Stack *stack = malloc(sizeof(Stack));
    if(stack == NULL) return 0;

    stack->first = NULL;
    stack->last = NULL;
    stack->size = 0;

    for (int i = 0; i < strlen(s); i++){
        PUSH(stack, s[i]);
        while((stack->size > 1) && CHECK(stack))
            CHECK(stack);
    }

    int a = stack->size;
    free(stack);
    return a;
}

int main(){
    char a[8] = {"ABFCACDB"};
    printf("%d", minLength(a));
    return 0;
}