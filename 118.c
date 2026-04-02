//Descrição: calcular as n linhas do triangulo de pascal

#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int **result;

    *returnSize = numRows;

    *returnColumnSizes = (int *)malloc(sizeof(int)*numRows);
    result = (int **)malloc(sizeof(int *)*numRows);
    if ( result == NULL ) exit(1);

    for ( int i = 0; i < numRows; i++ ) {
        result[i] = (int *)malloc(sizeof(int)*(i+1));
        if ( result[i] == NULL ) exit(1);

        (*returnColumnSizes)[i] = i + 1;
        result[i][0] = 1;
        result[i][i] = 1;

        if ( i > 1 ) {
            for ( int j = 1; j < i; j++ ) {
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
        }
    }

    return result;
}