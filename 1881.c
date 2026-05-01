#include <stdbool.h>
#include <stdlib.h>

char* maxValue(char* n, int x) {
    
    char *result, y = x + '0';
    int i = 0, j = 0;
    bool added = false;

    result = (char *)malloc(sizeof(char)*(strlen(n)+2));
    if ( result == NULL ) {
        return NULL;
    }

    if ( n[0] == '-' ) {
        result[0] = '-';
        i++;
        j++;
        while ( n[i] != '\0' ) {
            if ( n[i] > y && !added ) {
                result[j] = y;
                j++;
                result[j] = n[i];
                added = true;
            } else {
                result[j] = n[i];
            }
            i++;
            j++;
        }
    } else {
        while ( n[i] != '\0' ) {
            if ( n[i] < y && !added ) {
                result[j] = y;
                j++;
                result[j] = n[i];
                added = true;
            } else {
                result[j] = n[i];
            }
            i++;
            j++;
        }

    }

    if ( !added ) {
        result[j] = y;
        j++;
    }

    result[j] = '\0';

    return result;
}