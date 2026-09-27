#include <stdio.h>
#include "vetor.h"

int soma(int total, int num){
    return total + num;
}

int multiplicacao(int total, int num){
    return total * num;
}



int main(){

    Vetor vetor;

    LeVetor(&vetor);

    Operation opSoma, opMultiplicacao;
    opSoma = soma;
    opMultiplicacao = multiplicacao;

    printf("Soma: %d\n", AplicarOperacaoVetor(&vetor, opSoma));
    printf("Produto: %d\n", AplicarOperacaoVetor(&vetor, opMultiplicacao));
    
    return 0;
}