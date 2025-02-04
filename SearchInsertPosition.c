/*
    Dado um array ordenado de inteiros distintos e um valor alvo, retorna o índice se o alvo for encontrado. 
    Se não, retorna o índice onde ele estaria se fosse inserido em ordem.

    Autora: Andressa Von Ahnt
*/

#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target){
    int i;

    for (i = 0; i < numsSize; i++){
        if(nums[i] == target)
            return i;

        if(nums[i] > target)
            return i;
        
    }
    return i++;
}

int main(){
    int array[] = {1,3,5,6};

    printf("%d", searchInsert(array, 4, 7));
}