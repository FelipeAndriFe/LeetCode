//Descrição: Verifica se a string s é uma subsequência da string t

#include <stdbool.h>

bool isSubsequence(char* s, char* t) {
    
    int indexS = 0;
    bool result = false;

    for ( int i = 0; t[i] != '\0'; i++ ) {
        if ( t[i] == s[indexS] ) {
            indexS++;
        }
    }

    if ( s[indexS] == '\0' ) {
        result = true;
    }

    return result;
}