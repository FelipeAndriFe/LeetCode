//Descrição: dado um vetor de inteiros nums, calcular runningSum[i] = sum(nums[0]…nums[i]).

#include <stdlib.h>

int* runningSum(int* nums, int numsSize, int* returnSize) {
    int* result;
    *returnSize = numsSize;
    result = (int*)malloc(sizeof(int)*numsSize);
    if (result == NULL) exit(1);
    for (int i = 0; i < numsSize; i++){
        if (i == 0){
            result[i] = nums[i];
        } else {
            result[i] = nums[i] + result[i-1];
        }
    }
    return result;
}