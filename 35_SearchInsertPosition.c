/*
    Search Insert Position (35)
    Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
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