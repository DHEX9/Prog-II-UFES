#include <stdio.h>
#include "utils.h"

int main(){
    int tamanho;
    scanf("%d", &tamanho);

    int *vet = CriaVetor(tamanho);

    LeVetor(vet, tamanho);
    printf("%.2f", CalculaMedia(vet, tamanho));
    LiberaVetor(vet);

    return 0;
}