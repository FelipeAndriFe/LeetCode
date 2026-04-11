//Descrição: retornar o numero de caracteres removidos de uma string para que ela tenha <= k letras diferentes

#include <stdlib.h>

int minDeletion(char* s, int k) {
    int len, *ocorrencias = NULL, count = 0, c = 0, result = 0, i;
    len = strlen(s);
    
    for ( i = 0; i < len - 1; i++ ) {
        for ( int j = 0; j < len - 1 - i; j++ ) {
            if ( s[j] > s[j+1] ) {
                char temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }

    for ( i = 0; i < len; i++ ) {
        count++;
        if ( s[i+1] == '\0' || s[i] != s[i+1] ) {
            int *temp = (int *)realloc(ocorrencias, sizeof(int)*(c+1));
            if ( !temp ) exit(1);
            ocorrencias = temp;
            ocorrencias[c] = count;
            count = 0;
            c++;
        }
    }

    int d = c - k;
    if ( d <= 0 ) {
        free(ocorrencias);
        return 0;
    }

    for ( i = 0; i < c; i++ ) {
        for ( int j = 0; j < c - 1 - i; j++ ) {
            if ( ocorrencias[j] > ocorrencias[j+1] ) {
                int temp = ocorrencias[j];
                ocorrencias[j] = ocorrencias[j+1];
                ocorrencias[j+1] = temp;
            }
        }
    }

    for ( i = 0; i < c; i++ ) {
        result += ocorrencias[i];
        if ( d - (i + 1) <= 0 ) {
            free(ocorrencias);
            return result;
        }
    }

    return 0;
}