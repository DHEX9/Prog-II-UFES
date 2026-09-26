#include <stdio.h>
#include "pessoa.h"

int main(){

    int n;
    scanf("%d", &n);
    tPessoa vetPessoas[n];
    tPessoa pessoa;

    for(int i = 0; i < n; i++){  
        pessoa = CriaPessoa();
        LePessoa(&pessoa);
        vetPessoas[i] = pessoa;
    }

    AssociaFamiliasGruposPessoas(vetPessoas);

    for(int i = 0; i < n; i++){
        ImprimePessoa(&vetPessoas[i]);
    }

    return 0;
}