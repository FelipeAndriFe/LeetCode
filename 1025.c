//Descrição: Resposta para o problema "Divisor Game"

#include <stdbool.h>

bool divisorGame(int n) {
    
    if ( n % 2 == 0 ) {
        return true;
    }

    return false;
}