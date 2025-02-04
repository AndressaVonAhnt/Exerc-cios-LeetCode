#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

char* clearDigits(char* s) {
    char *string = malloc(strlen(s) + sizeof(char));
    if(string == NULL) return NULL;
    int top = -1;

    for(int i = 0; i <= strlen(s); i++){
        if((int)s[i] >= 48 && (int)s[i] <= 57){
            if(top >= 0){
                string[top] = '\0';
                top--;
            }
        }else{
            top++;
            string[top] = s[i];
        }
    }
    return string;
}

int main(){
    printf("%s", clearDigits("And1sa"));
    return 0;
}