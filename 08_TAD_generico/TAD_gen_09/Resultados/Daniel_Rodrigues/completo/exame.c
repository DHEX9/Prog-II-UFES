#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exame.h"

/*
    Estrutura do tipo Exame contendo os atributos necessários para a manipulação
*/
struct _Exame{
    char nomeMedico[100], nomePaciente[100], solicitacaoExame[100];
};

/*
    Função que cria uma Exame e retorna o seu endereço de memória
    @param nomeMedicamento: nome do medicamento prescrito na Exame
    @param nomePaciente: nome do paciente para quem a Exame foi prescrita
    @param nomeMedico: nome do médico que prescreveu a Exame
    @param instrucoes: instruções para o uso do medicamento
    @return: endereço de memória da Exame criada
*/
Exame *criaExame(char *solicitacaoExame, char *nomePaciente, char *nomeMedico){
    Exame *e = malloc(1 * sizeof(Exame));
    if(!e) exit(1);

    strcpy(e->nomeMedico, nomeMedico);
    strcpy(e->nomePaciente, nomePaciente);
    strcpy(e->solicitacaoExame, solicitacaoExame);
    
    return e;
}

/*
    Função que lê os dados de uma Exame a partir da entrada padrão de acordo com a especificação
    @return: endereço de memória da Exame lida
*/
Exame *leExame(){
    char nomeMedico[100], nomePaciente[100], solicitacaoExame[100];

    scanf(" %[^\n]\n", nomeMedico);
    scanf(" %[^\n]\n", nomePaciente);
    scanf(" %[^\n]\n", solicitacaoExame);
    
    return criaExame(solicitacaoExame, nomePaciente, nomeMedico);
}

/*
    Função que calcula o preço de impressão de uma Exame de acordo com a especificação
    @param dado: ponteiro genérico para a Exame a ser calculada
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão da Exame
*/
float calculaPrecoImpressaoExame(void *dado, float precoCaractere){
    Exame *e = (Exame*) dado;
    return (strlen(e->nomeMedico) + strlen(e->nomePaciente) + strlen(e->solicitacaoExame)) * precoCaractere;
}

/*
    Função que imprime uma Exame de acordo com a especificação (veja os casos de teste)
    @param dado: ponteiro genérico para a Exame a ser impressa
*/
void imprimeExame(void *dado){
    Exame *e = (Exame*) dado;

    printf("- - EXAME - -\n");
    printf("PACIENTE: %s\n", e->nomePaciente);
    printf("SOLICITACAO: %s\n", e->solicitacaoExame);
    printf("MEDICO: %s\n", e->nomeMedico);
    printf("- - - - - - -\n");
}

/*
    Função que desaloca uma Exame
    @param dado: ponteiro genérico para a Exame a ser desalocada
*/
void desalocaExame(void *dado){
    Exame *e = (Exame*) dado;
    free(e);
}
