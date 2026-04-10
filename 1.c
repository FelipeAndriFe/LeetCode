//Descrição: Achar em um array os dois numeros que somados dão um determinado alvo

#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    for ( int i = 0; i < numsSize - 1; i++ ) {
        for ( int j = 1 + i; j < numsSize; j++ ) {
            if ( nums[i] + nums[j] == target ) {
                int *result;
                result = (int *)malloc(sizeof(int)*2);
                if ( !result ) exit(1);

                result[0] = i;
                result[1] = j;

                *returnSize = 2;
                return result;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}