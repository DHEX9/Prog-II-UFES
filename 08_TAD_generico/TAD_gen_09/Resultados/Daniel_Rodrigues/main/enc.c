#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Enc.h"

/*
    Estrutura do tipo Enc contendo os atributos necessários para a manipulação
*/
struct _Enc{
    char nomeMedico[100], nomePaciente[100], enc[50], motivoEnc[200];
};

/*
    Função que cria uma Enc e retorna o seu endereço de memória
    @param nomeMedicamento: nome do medicamento prescrito na Enc
    @param nomePaciente: nome do paciente para quem a Enc foi prescrita
    @param nomeMedico: nome do médico que prescreveu a Enc
    @param instrucoes: instruções para o uso do medicamento
    @return: endereço de memória da Enc criada
*/
Enc *criaEnc(char *enc, char *nomePaciente, char *nomeMedico, char *motivoEnc){
    Enc *e = malloc(1 * sizeof(Enc));
    if(!e) exit(1);

    strcpy(e->nomeMedico, nomeMedico);
    strcpy(e->nomePaciente, nomePaciente);
    strcpy(e->enc, enc);
    strcpy(e->motivoEnc, motivoEnc);
    
    return e;
}

/*
    Função que lê os dados de uma Enc a partir da entrada padrão de acordo com a especificação
    @return: endereço de memória da Enc lida
*/
Enc *leEnc(){
    char nomeMedico[100], nomePaciente[100], enc[50], motivoEnc[200];

    scanf(" %[^\n]\n", nomeMedico);
    scanf(" %[^\n]\n", nomePaciente);
    scanf(" %[^\n]\n", enc);
    scanf(" %[^\n]\n", motivoEnc);
    
    return criaEnc(enc, nomePaciente, nomeMedico, motivoEnc);
}

/*
    Função que calcula o preço de impressão de uma Enc de acordo com a especificação
    @param dado: ponteiro genérico para a Enc a ser calculada
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão da Enc
*/
float calculaPrecoImpressaoEnc(void *dado, float precoCaractere){
    Enc *e = (Enc*) dado;
    return (strlen(e->nomeMedico) + strlen(e->nomePaciente) + strlen(e->enc) + strlen(e->motivoEnc)) * precoCaractere;
}

/*
    Função que imprime uma Enc de acordo com a especificação (veja os casos de teste)
    @param dado: ponteiro genérico para a Enc a ser impressa
*/
void imprimeEnc(void *dado){
    Enc *e = (Enc*) dado;

    printf("- - ENCAMINHAMENTO - -\n");
    printf("PACIENTE: %s\n", e->nomePaciente);
    printf("ESPECIALIDADE: %s\n", e->enc);
    printf("MOTIVO: %s\n", e->motivoEnc);
    printf("MEDICO: %s\n", e->nomeMedico);
    printf("- - - - - - - - - - - -\n");
}

/*
    Função que desaloca uma Enc
    @param dado: ponteiro genérico para a Enc a ser desalocada
*/
void desalocaEnc(void *dado){
    Enc *e = (Enc*) dado;
    free(e);
}
