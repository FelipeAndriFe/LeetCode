//Descrição: Verifica se existem duplicadas no vetor (excedeu o tempo)

#include <stdbool.h>

bool containsDuplicate(int* nums, int numsSize) {
    
    bool result = false;

    for ( int i = 0; i < numsSize; i++ ) {
        for ( int j = 1 + i; j < numsSize; j++ ) {
            if ( nums[i] == nums[j] ) {
                result = true;
                break;
            }
        }
        if ( result == true ) {
            break;
        }
    }

    return result;
}