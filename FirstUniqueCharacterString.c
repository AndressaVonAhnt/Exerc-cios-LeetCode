#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int search(char *s, char c, int j){
    for(int i = 0; i <= strlen(s); i++){
        if(c == s[i] && i != j)
            return 0;
    }
    return 1;
}

int firstUniqChar(char* s) {
    for(int i = 0; i < strlen(s); i++){
        if(search(s, s[i], i))
            return i;
    }
    return -1;
}

int main(){
    printf("%d", firstUniqChar("aabb"));
    return 0;
}