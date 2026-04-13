//Descrição: Acha o caminho mais curto em um vetor de um numero target começando em um indice start

int getMinDistance(int* nums, int numsSize, int target, int start) {
    
    int iFrente = 0, iTras = 0, i;

    if ( nums[start] == target ) {
        return 0;
    }

    for ( iFrente = start; iFrente < numsSize; iFrente++ ) {
        if ( nums[iFrente] == target ) {
            break;
        }
    }

    for ( iTras = start; iTras >= 0; iTras-- ) {
        if ( nums[iTras] == target ) {
            break;
        }
    }

    if ( iTras > -1 && iFrente < numsSize ) {
        if ( abs(iFrente - start) < abs(iTras - start) ) {
            return abs(iFrente - start);
        } else {
            return abs(iTras - start);
        }
    } else if ( iTras == -1 && iFrente < numsSize ) {
        return abs(iFrente - start);
    } else {
        return abs(iTras - start);
    }

    return 0;
}