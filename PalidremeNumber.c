/*
    Este código verifica se o número é um palíndromo, ou seja, se o número é igual de trás pra frente.

    Autora: Andressa Von Ahnt
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(int x) {
    char str1[10], *str2;
    int i, j=0;

    sprintf(str1, "%d", x);

    if((str2 = (char *)malloc((sizeof(char) * strlen(str1)) + 1)) == NULL){
        printf("Error allocating memory");
        exit(1);
    }

    size_t size = strlen(str1) - 1;

    for (i = size; i >= 0; i--){
        str2[j] = str1[i];
        j++;
    }
    str2[j] = '\0';
    
    if(!strcmp(str1, str2))
        return 1;
    else
        return 0;
}

int main(){
    printf("%d", isPalindrome(101));
    return 0;
}