/*
    First Unique Character in a String (387)
    Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
*/

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