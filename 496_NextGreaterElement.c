/*
    Next Greater Element I (496)
    The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
    You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
    For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
    Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *ans;
    ans = (int *)malloc(sizeof(int) * nums1Size);

    if(ans == NULL){
        printf("Error allocating memory");
        exit(1);
    }

    int top = -1;
    bool equal = 0;

    for (int i = 0; i < nums1Size; i++){
        for (int j = 0; j < nums2Size; j++){
            if(equal == 1){
                if(nums2[j] > nums1[i]){
                    ans[++top] = nums2[j];
                    equal = 0;
                    break;
                }
            }

            if(nums1[i] == nums2[j])
                equal = 1;
        }
        if(equal){
            ans[++top] = -1;
            equal = 0;
        }
    }
    
    *returnSize = ++top;
    return ans;
}

int main(){
    int *a, nums1[] = {2, 4}, nums2[] = {1, 2, 3, 4}, returnSize;

    a = nextGreaterElement(nums1, 2, nums2, 4, &returnSize);

    for (int i = 0; i < returnSize; i++){
        printf("%d ", a[i]);
    }
    
}