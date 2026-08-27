#include <stdio.h>
#define MAX 20
#define INDEFINIDO -1

typedef struct {
    int lin, col;
    int mapa[MAX][MAX];
}Matriz;

//Retorna mapa
Matriz criaMapa(int lin, int col){

    //Cria variaveis Auxiliares
    int bin;
    Matriz matriz;
    matriz.mapa[lin][col];
    matriz.lin = lin;
    matriz.col = col;

    //Cria mapa
    for (int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &bin);
        }
    }

    return matriz;
}

Matriz movimenta(Matriz matriz, char move[]){

}

int main(){

    // ------- Prepareção de Ambiente -------

    //Variaveis da Matriz
    int lin, col;
    scanf("%d %d", &lin, &col);

    Matriz matriz = criaMapa(lin, col);

    //Variaveis de inicio de chegada
    int xInicio, yInicio ,xChegada, yChegada;
    scanf("%d %d %d %d", &xInicio, &yInicio, &xChegada, &yChegada);

    //Variavel de movimento
    int rastro[MAX][MAX];
    char move[5];
    scanf("%s", &move);

    // ------- Running -------

    while(1){
        
    }
    
    return 0;
}