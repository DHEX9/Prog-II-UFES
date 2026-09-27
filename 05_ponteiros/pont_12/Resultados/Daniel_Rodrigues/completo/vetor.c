#include <stdio.h>
#include "vetor.h"

/**
 * Lê um vetor da entrada padrão.
 * 
 * @param vetor Ponteiro para o vetor que será lido.
 */
void LeVetor(Vetor *vetor){
    scanf("%d", &vetor->tamanhoUtilizado);

    for(int i = 0; i < vetor->tamanhoUtilizado; i++){
        scanf("%d", &vetor->elementos[i]);
    }
}

/**
 * Aplica uma operação em um vetor.
 * 
 * @param vetor Ponteiro para o vetor que será utilizado.
 * @param op Ponteiro para a função que será aplicada.
 * @return O resultado da operação.
*/
int AplicarOperacaoVetor(Vetor *vetor, Operation op){

    if (vetor->tamanhoUtilizado == 0 || vetor->tamanhoUtilizado > TAMANHO_MAXIMO) return 0;

    int total = vetor->elementos[0];

    for(int i = 1; i < vetor->tamanhoUtilizado; i++){
        total = op(total, vetor->elementos[i]);
    }
    
    return total;
}