//Descrição: dado um inteiro n, retornar uma matriz de strings com mensagens caso os numeros de 1 a n forem divisíveis por 3 e\ou 5

#include <stdlib.h>
#include <string.h>

char** fizzBuzz(int n, int* returnSize) {
    char **answer = (char **)malloc(sizeof(char *)*n);
    if (answer == NULL) exit(1);
    *returnSize = n;

    for (int i = 1; i <= n; i++){
        answer[i-1] = (char *)malloc(sizeof(char)*9);
        if (i % 15 == 0){
            strcpy(answer[i-1], "FizzBuzz");
        }else if (i % 3 == 0){
            strcpy(answer[i-1], "Fizz");
        } else if (i % 5 == 0){
            strcpy(answer[i-1], "Buzz");
        } else {
            sprintf(answer[i-1], "%d", i);
        }
    }

    return answer;
}