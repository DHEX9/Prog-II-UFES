#include <stdio.h>
#include "rolagem.h"

// ------- Le palavras -------
void lePalavras(char (*msg)[TAM_MAX_MSG], int *numMsgs){

    scanf("%d", numMsgs);

    for(int i = 0; i < *numMsgs; i++){
        scanf(" %999[^\n]", msg[i]);
    }
}

int main(){

    int nRolgem; //Passos de rolagem
    scanf("%d", &nRolgem);
    RolaMsg(lePalavras, 30, nRolgem);

}