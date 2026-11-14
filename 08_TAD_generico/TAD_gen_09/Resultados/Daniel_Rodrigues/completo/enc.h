

#ifndef _ENC_H
#define _ENC_H

/*
    Estrutura do tipo Enc contendo os atributos necessários para a manipulação
*/
typedef struct _Enc Enc;

/*
    Função que cria uma Enc e retorna o seu endereço de memória
    @param nomeMedicamento: nome do medicamento prescrito na Enc
    @param nomePaciente: nome do paciente para quem a Enc foi prescrita
    @param nomeMedico: nome do médico que prescreveu a Enc
    @param instrucoes: instruções para o uso do medicamento
    @return: endereço de memória da Enc criada
*/
Enc *criaEnc(char *enc, char *nomePaciente, char *nomeMedico, char *motivoEnc);

/*
    Função que lê os dados de uma Enc a partir da entrada padrão de acordo com a especificação
    @return: endereço de memória da Enc lida
*/
Enc *leEnc();

/*
    Função que calcula o preço de impressão de uma Enc de acordo com a especificação
    @param dado: ponteiro genérico para a Enc a ser calculada
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão da Enc
*/
float calculaPrecoImpressaoEnc(void *dado, float precoCaractere);

/*
    Função que imprime uma Enc de acordo com a especificação (veja os casos de teste)
    @param dado: ponteiro genérico para a Enc a ser impressa
*/
void imprimeEnc(void *dado);

/*
    Função que desaloca uma Enc
    @param dado: ponteiro genérico para a Enc a ser desalocada
*/
void desalocaEnc(void *dado);

#endif