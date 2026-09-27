#include <stdio.h>
#include "calculadora.h"

float soma(float num1, float num2){
    return num1 + num2;
}

float subtracao(float num1, float num2){
    return num1 - num2;
}

float multiplicacao(float num1, float num2){
    return num1 * num2;
}

float divisao(float num1, float num2){
    return num1 / num2;
}

CalculatoraCallback opcao(char c, float num1, float num2){

    switch (c){
        case 'a':
            printf("%.2f + %.2f = ", num1, num2);
            return soma;
        
        case 's':
            printf("%.2f - %.2f = ", num1, num2);
            return subtracao;
        
        case 'm':
            printf("%.2f x %.2f = ", num1, num2);
            return multiplicacao;

        case 'd':
            printf("%.2f / %.2f = ", num1, num2);
            return divisao; 

        default:
            return NULL;
    }
}

int main(){
    char c;
    float num1, num2;
    CalculatoraCallback operacao;

    scanf("%c", &c);

    while (c != 'f'){

        scanf("%f %f", &num1, &num2);
        operacao = opcao(c, num1, num2);

        printf("%.2f\n", Calcular(num1, num2, operacao));

        scanf(" %c", &c);
    }
    
    return 0;
}