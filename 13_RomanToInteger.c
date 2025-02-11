/*
    Roman to Integer (13)
    Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
    For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
    Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int symbol(char c){
    c = toupper(c);

    if(c == 'I')
        return 1;
    else if(c == 'V')
            return 5;
        else if(c == 'X')
                return 10;
            else if(c == 'L')
                    return 50;
                else if(c == 'C')
                        return 100;
                    else if(c == 'D')
                            return 500;
                        else if(c == 'M')
                                return 1000;
                            else 
                                return 0;
}

int romanToInt(char* s) {
    int a=0;

    for (int i = 0; i < strlen(s); i++){
        if(symbol(s[i]) == 0){
            return 0;
        }else{
            if((s[i] != s[i+1]) && (s[i+1] != '\0')){ 
                if(symbol(s[i]) < symbol(s[i+1])){ 
                    a += (symbol(s[i+1]) - symbol(s[i]));
                    i++;
                }else{ 
                    a += symbol(s[i]);
                }
            }else {
                a += symbol(s[i]);
            }
        }
    }
    return a;
}

int main(){
    char s[16];
    int i;

    printf("Enter roman number: ");
    if(fgets(s, 16, stdin) == NULL){
        printf("Error reading number\n");
        exit(1);
    }
    s[strlen(s)-1] = '\0';

    i = romanToInt(s);

    if(i == 0)
        printf("Invalid number\n");
    else
        printf("Integer: %d\n", romanToInt(s));
}