#include <stdio.h>

int SomaElementosPares(int vet[], int numElementos, int i){
    if(i == numElementos){
        return 0;
    }

    if(vet[i] % 2 == 0){
        return vet[i] + SomaElementosPares(vet, numElementos, i + 1);
    }
    return SomaElementosPares(vet, numElementos, i + 1);
}

int main(){
    int n, num;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        int numElementos;
        scanf("%d", &numElementos);

        int vet[numElementos];

        for(int i = 0; i < numElementos; i++){
            scanf("%d", &num);
            vet[i] = num;
        }

        printf("%d\n", SomaElementosPares(vet, numElementos, 0));
    }
    
    return 0;
}