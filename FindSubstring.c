#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    int index = -1, j=0, test = 0;
    
    for (int i = 0; i < strlen(haystack); i++){
        if(haystack[i] == needle[j]){
            if(test == 0){
                index = i;
                test = 1;
            }

            if((test == 1) && (needle[j+1] == '\0'))
                return index;

            j++;

        }else{
            test = 0;
            i -= j;
            j=0;
            index = -1;
        }  
    }
    if(needle[j] == '\0')
        return index;
    else
        return -1;
}

int main(){
    printf("%d", strStr("mississippi", "issip"));
    return 0;
}