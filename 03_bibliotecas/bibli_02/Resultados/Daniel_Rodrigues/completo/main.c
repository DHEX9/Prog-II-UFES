#include <stdio.h>
#include "matrix_utils.h"

void menu(){
    printf(
        "1 - Somar matrizes\n"
        "2 - Subtrair matrizes\n"
        "3 - Multiplicar matrizes\n"
        "4 - Multiplicacao de uma matriz por escalar\n"
        "5 - Transposta de uma matriz\n"
        "6 - Encerrar o programa\n"
        "Opcao escolhida: \n"
    );
}

int leOpcao(){
    int opcao;
    scanf("%d", &opcao);

    return opcao;
}

void exec(int opcao, int rows1, int cols1, int rows2, int cols2, int matriz1[rows1][cols1], int matriz2[rows2][cols2]){

    int result[rows1][cols1];
    int escalar, op; 

    switch(opcao){
        case 1:
            if(possible_matrix_sum(rows1, cols1, rows2, cols2)){
                matrix_add(rows1, cols1, matriz1, rows2, cols2, matriz2, result);
                matrix_print(rows1, cols1, result);
            }
            else{
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
            
            break;

        case 2:
            if(possible_matrix_sub(rows1, cols1, rows2, cols2)){
                matrix_sub(rows1, cols1, matriz1, rows2, cols2, matriz2, result);
                matrix_print(rows1, cols1, result);
            }
            else{
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }

            break;

        case 3:
            if(possible_matrix_multiply(cols1, rows2)){
                matrix_multiply(rows1, cols1, matriz1, rows2, cols2, matriz2, result);
                matrix_print(rows1, cols2, result);
            }
            else{
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
            }

            break;

        case 4:
            scanf("%d %d", &escalar, &op);

            if(op == 1){
                scalar_multiply(rows1, cols1, matriz1, escalar);
                matrix_print(rows1, cols1, matriz1);
            }
            else if(op == 2){
                scalar_multiply(rows2, cols2, matriz2, escalar);
                matrix_print(rows2, cols2, matriz2);
            }
            
            break;

        case 5:
            transpose_matrix(rows1, cols1, matriz1, result);
            matrix_print(cols1, rows1, result);

            transpose_matrix(rows2, cols2, matriz2, result);
            matrix_print(cols2, rows2, result);

            break;

        default:
            break;
    }
}

int main(){
    
    int opcao, rows1, cols1, rows2, cols2;

    scanf("%d %d", &rows1, &cols1);
    int matriz1[rows1][cols1];
    matrix_read(rows1, cols1, matriz1);

    scanf("%d %d", &rows2, &cols2);
    int matriz2[rows2][cols2];
    matrix_read(rows2, cols2, matriz2);

    while (1){

        menu();

        opcao = leOpcao();

        if(opcao == 6){
            break;
        }

        exec(opcao, rows1, cols1, rows2, cols2, matriz1, matriz2);
        
    }
    
    return 0;
}