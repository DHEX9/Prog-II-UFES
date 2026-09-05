#include <stdio.h>

int ContaOcorrencias(int vet[], int i, int numElementos, int numeroProcurado){
    if(i == numElementos){
        return 0;
    }

    if(vet[i] == numeroProcurado){
        return 1 + ContaOcorrencias(vet, i + 1, numElementos, numeroProcurado);
    }

    return ContaOcorrencias(vet, i + 1, numElementos, numeroProcurado);
}

int main(){

    // ------- Prepareção de Ambiente -------
    int n, numeroProcurado, numElementos, num;
    scanf("%d", &n);

    // ------- Running -------
    while(n--){
        scanf("%d %d", &numeroProcurado, &numElementos);
        int vet[numElementos];

        for(int i = 0; i < numElementos; i++){
            scanf("%d", &num);
            vet[i] = num;
        }

        printf("%d\n", ContaOcorrencias(vet, 0, numElementos, numeroProcurado));
    }

    return 0;
}