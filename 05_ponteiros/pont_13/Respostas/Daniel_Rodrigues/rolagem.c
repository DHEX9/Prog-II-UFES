#include <stdio.h>
#include <string.h>
#include "rolagem.h"

/**
 * @brief Ponteiro para função que recebe um array de mensagens e o número de mensagens para rolagem.
 * 
 * @param msg Array de mensagens.
 * @param numMsgs Número de mensagens.
 */
typedef void (*FptrMsg)(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int * numMsgs);

/**
 * @brief Dispara a função de rolagem de mensagens.
 * 
 * @param FuncMsg Ponteiro para a função que recebe um array de mensagens e o número de mensagens.
 * @param tamanhoDisplay Tamanho do display.
 * @param tempoFim Tempo de duração da rolagem, que diz respeito a quantidade de deslocamento no painel.
 */
void RolaMsg(FptrMsg FuncMsg, int tamanhoDisplay, int tempoFim){

    char msg[NUM_MAX_MSGS][TAM_MAX_MSG];
    int numMsgs = 0;

    char texto[NUM_MAX_MSGS * TAM_MAX_MSG];

    FuncMsg(msg, &numMsgs);

    for(int i = 0; i < numMsgs; i++){
        strcat(texto, msg[i]);
    }

    int total = strlen(texto);

    for(int i = 0; i < tempoFim; i++){
        for(int j = 0; j < tamanhoDisplay; j++){
            putchar(texto[(i + j) % total]);
        }
        printf("\n\033[H\033[J");
    }
}