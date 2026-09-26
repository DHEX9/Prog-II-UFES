#include <stdio.h>
#include <string.h>
#include "tDepartamento.h"

int confereRepetido(tDepartamento *vetor_dptos, int num_dptos, char *nome);

int main(){

    int n; // N departamentos
    int m1,m2, m3; // Média do cursos
    int num_dptos = 0;
    tDepartamento vetor_dptos[10];
    char nome[STRING_MAX], diretor[STRING_MAX], curso1[STRING_MAX], curso2[STRING_MAX], curso3[STRING_MAX];

    scanf("%d", &n);

    printf("\n");
    
    while (n--){

        scanf(" %49[^\n]", &nome);
        if(confereRepetido(vetor_dptos, num_dptos, nome)) continue;

        scanf(" %49[^\n]", &diretor);
        scanf(" %49[^\n] %49[^\n] %49[^\n]", &curso1, &curso2, &curso3);
        scanf("%d %d %d", &m1, &m2, &m3);
        
        if(m1 < 0 || m2 < 0 || m3 < 0){
            printf("Digite um departamento com médias válidas\n");
            n++; 
            continue;
        }

        vetor_dptos[num_dptos++] = CriaDepartamento(curso1, curso2, curso3, nome, m1, m2, m3, diretor);
    }
    
    OrdenaDepartamentosPorMedia(vetor_dptos, num_dptos);

    for(int i = 0; i < num_dptos; i++){
        ImprimeAtributosDepartamento(vetor_dptos[i]);
    }

    return 0;
}

// Retorna 1 se tiver repedido
int confereRepetido(tDepartamento *vetor_dptos, int num_dptos, char *nome){
    
    for(int i = 0; i < 0; i++){
        if(!strcmp(vetor_dptos[i].nome, nome)) return 1;
    }

    return 0;
}