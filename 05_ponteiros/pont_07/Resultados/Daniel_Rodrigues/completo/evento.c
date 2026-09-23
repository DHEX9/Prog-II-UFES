#include <stdio.h>
#include "evento.h"

/**
 * Cadastra um novo evento no calendário e o insere na próxima posição do array.
 *
 * @param eventos Array de eventos onde o novo evento será cadastrado.
 * @param numEventos Ponteiro para o número atual de eventos cadastrados.
 */
void cadastrarEvento(Evento* eventos, int* numEventos){
    
    if(*numEventos > MAX_EVENTOS){
        printf("Limite de eventos atingido!\n");
        return;
    }

    Evento e;
    scanf("%s", e.nome);
    scanf("%2d %2d %4d", &e.dia, &e.mes, &e.ano);
    eventos[(*numEventos)++] = e;
    printf("Evento cadastrado com sucesso!\n");
}

/**
 * Exibe todos os eventos cadastrados no calendário.
 *
 * @param eventos Array de eventos a serem exibidos.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void exibirEventos(Evento* eventos, int* numEventos){
    if(*numEventos == 0){
        printf("Nenhum evento cadastrado.\n");
        return;
    }

    printf("Eventos cadastrados:\n");

    for(int i = 0; i < *numEventos; i++){
        printf("%d - %s - %d/%d/%d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);
    }
}

/**
 * Troca a data de um evento específico no calendário.
 *
 * @param eventos Array de eventos onde o evento será modificado.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarDataEvento(Evento* eventos, int* numEventos){
    int i;
    scanf("%d", &i);

    if(i < 0 || i > *numEventos){
        printf("Indice invalido!\n");
        return;
    }
    
    scanf("%2d %2d %4d", &eventos[i].dia, &eventos[i].mes, &eventos[i].ano);
    printf("Data modificada com sucesso!\n");
}

/**
 * Troca a posição de dois eventos, a partir do índice, dentro do array de eventos.
 *
 * @param eventos Array de eventos onde a troca será realizada.
 * @param indiceA Ponteiro para o primeiro índice.
 * @param indiceB Ponteiro para o segundo índice.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){

    if((*indiceA < 0 || *indiceA >= *numEventos) || (*indiceB < 0 || *indiceB >= *numEventos)){
        printf("Indices invalidos!\n");
        return;
    }

    Evento e = eventos[*indiceA];
    eventos[*indiceA] = eventos[*indiceB];
    eventos[*indiceB] = e;

    printf("Eventos trocados com sucesso!\n");
}