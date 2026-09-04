#include <stdio.h>
#define MAX_MAPA 20
#define MAX_RASTRO 200
#define INDEFINIDO -1

typedef struct {
    int mapa[MAX_MAPA][MAX_MAPA];
}Matriz;

typedef struct {
    int x;
    int y;
}Player;

//Retorna mapa
Matriz criaMapa(int lin, int col){

    //Cria variaveis Auxiliares
    int bin;
    Matriz matriz;

    //Cria mapa
    for (int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &matriz.mapa[i][j]);
        }
    }

    return matriz;
}

Player movimentacao(Matriz matriz, int lin, int col, Player player, char move[]){

    //Todas as possibilidades de direção
    for (int i = 0; i < 4; i++){

        switch (move[i]){

            case 'C':
                if(matriz.mapa[player.y - 1][player.x] == 0 && player.y - 1 >= 0){
                    player.y -= 1;

                    return player;
                }
                
                break;
            
            case 'B':
                if(matriz.mapa[player.y + 1][player.x] == 0 && player.y + 1 <= lin){
                    player.y += 1;

                    return player;
                }
                
                break;
                
            case 'D':
                if(matriz.mapa[player.y][player.x + 1] == 0 && player.x + 1 <= col){
                    player.x += 1;

                    return player;
                }

                break;
            
            case 'E':
                if(matriz.mapa[player.y][player.x - 1] == 0 && player.x - 1 >= 0){
                    player.x -= 1;

                    return player;
                }

                break;

            default:
                break;
        }
    }

    player.x = INDEFINIDO;
    player.y = INDEFINIDO;

    return player;
}

int main(){

    // ------- Prepareção de Ambiente -------

    //Variaveis da Matriz
    int lin, col;
    scanf("%d %d", &lin, &col);

    Matriz matriz = criaMapa(lin, col);

    //Variaveis de inicio de chegada
    Player player;
    int xChegada, yChegada;
    scanf("%d %d %d %d", &player.y, &player.x, &yChegada, &xChegada);

    //1-based para 0-based
    player.x--;
    player.y--;
    xChegada--;
    yChegada--;
    lin--;
    col--;

    //Variavel de movimento
    int rastro[MAX_RASTRO][2], count = 0;
    char move[5];
    scanf("%s", &move);

    // ------- Running -------

    rastro[count][0] = player.y;
    rastro[count++][1] = player.x;

    do{

        matriz.mapa[player.y][player.x] = 1;

        player = movimentacao(matriz, lin, col, player, move);

        if(player.x == INDEFINIDO && player.y == INDEFINIDO){
            break;
        }

        rastro[count][0] = player.y;
        rastro[count++][1] = player.x;
        
    }while((player.x != xChegada || player.y != yChegada));

    printf("(%d,%d)", rastro[0][0] + 1, rastro[0][1] + 1);

    for(int i = 1; i < count; i++){
        printf(" (%d,%d)", rastro[i][0] + 1, rastro[i][1] + 1);
    }
    
    return 0;
}