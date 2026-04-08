//Descrição: Retorna a maior sequencia de 1's consecutivos

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int count = 0, longest = 0;
    
    for ( int i = 0; i < numsSize; i++ ) {
        if ( nums[i] == 1 ) {
            count++;
            if ( count > longest ) {
                longest = count;
            }
        } else {
            count = 0;
        }
    }
    
    return longest;
}