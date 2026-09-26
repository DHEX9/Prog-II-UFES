#include <stdio.h>
#include <string.h>
#include "tDepartamento.h"

/**
 * @brief Cria um departamento com os dados passados via parâmetro
 *
 *
 * @param *curso1 Ponteiro para string que contém o nome do primeiro curso do departamento
 * @param *curso2 Ponteiro para string que contém o nome do segundo curso do departamento
 * @param *curso3 Ponteiro para string que contém o nome do terceiro curso do departamento
 * @param *nome Ponteiro para string que contém o nome do departamento
 * @param m1 Nota do primeiro curso (curso1)
 * @param m2 Nota do segundo curso (curso2)
 * @param m3 Nota do terceiro curso (curso3)
 * @param *diretor Ponteiro para string que contém o nome do diretor/chefe do departamento
 */
tDepartamento CriaDepartamento( char *curso1, char *curso2, char *curso3, char *nome, int m1, int m2, int m3, char *diretor ){
    tDepartamento dp;
    strcpy(dp.nome, nome);
    strcpy(dp.diretor, diretor);
    strcpy(dp.curso1, curso1);
    strcpy(dp.curso2, curso2);
    strcpy(dp.curso3, curso3);
    dp.m1 = m1;
    dp.m2 = m2;
    dp.m3 = m3;

    return dp;
}

/**
 * @brief Imprime os atributos de um departamento em tela
 *
 * @param depto - Um departamento que terá seus dados impressos em tela
 */

void ImprimeAtributosDepartamento(tDepartamento depto){
    printf(
        "Departamento: %s\n"
        "   Diretor: %s\n"
        "   1o curso: %s\n"
        "   Media do 1o curso: %d\n"
        "   2o curso: %s\n"
        "   Media do 2o curso: %d\n"
        "   3o curso: %s\n"
        "   Media do 3o curso: %d\n"
        "   Media dos cursos: %.2f\n",
        depto.nome,
        depto.diretor,
        depto.curso1,
        depto.m1,
        depto.curso2,
        depto.m2,
        depto.curso3,
        depto.m3,
        (float)(depto.m1 + depto.m2 + depto.m3) / 3
    );
}

/**
 * @brief Ordena os departamentos de acordo com as médias das notas de cada um dos seus três cursos (da maior para a menor).
 *
 * @param *vetor_deptos - Ponteiro para um vetor de departamentos
 * @param num_deptos - O número de departamentos contidos no vetor_deptos
 */
void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos){
    float m1, m2;
    tDepartamento dp;

    for(int i = 0; i < num_deptos - 1; i--){
        for(int j = 0; j < i; j++){

            m1 = (vetor_deptos[j].m1 + vetor_deptos[j].m2 + vetor_deptos[j].m3) / 3;
            m1 = (vetor_deptos[j + 1].m1 + vetor_deptos[j + 1].m2 + vetor_deptos[j + 1].m3) / 3;

            if(m1 < m2){
                dp = vetor_deptos[j];
                vetor_deptos[j] = vetor_deptos[j + 1];
                vetor_deptos[j + 1] = dp;
            }
        }
    }
}