/*
    Remove Duplicates from Sorted Array (26)
    Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
*/

#include <stdio.h>
#include <stdlib.h>

void shiftArrayLeft(int* arr, int size){
    if (size <= 1) 
        return;
    
    int first = arr[0];

    for (int i = 0; i < size - 1; i++) 
        arr[i] = arr[i + 1];
    
    arr[size - 1] = first;
}

int removeDuplicates(int* nums, int numsSize) {
    int k = numsSize, *ptr;
    
    for (int i = 0; i < k; i++){
        for (int j = 1; j < k; i++){
            if(nums[i] == nums[j]){
                k--;
                ptr = &(nums[j]);
                shiftArrayLeft(ptr, k-i);
            }
        }
    }

    return k;
}

int main(){
    int nums[] = {1, 1, 2, 3, 2, 8}; 
    int expectedNums[] = {1, 2}; 
    int i;

    int k = removeDuplicates(nums, 3);

    for (i = 0; i < k; i++) {
        nums[i] == expectedNums[i];
    }

    if(i == k)
        printf("Accepted");
}