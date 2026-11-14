#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila_imp.h"
#include "documento.h"
#include "receita.h"
#include "exame.h"
#include "enc.h"

int main(){

    float preco;
    char cmd[100];

    scanf("%f", &preco);

    FilaImp *f = criaFilaImp();
    
    while(scanf(" %[^\n]\n", cmd) == 1){
        
        if(!strcmp(cmd, "RECEITA")){
            insereDocumentoFilaImp(f, leReceita(), imprimeReceita, desalocaReceita, calculaPrecoImpressaoReceita);
        }
        if(!strcmp(cmd, "ENCAMINHAMENTO")){
            insereDocumentoFilaImp(f, leEnc(), imprimeEnc, desalocaEnc, calculaPrecoImpressaoEnc);
        }
        if(!strcmp(cmd, "EXAME")){
            insereDocumentoFilaImp(f, leExame(), imprimeExame, desalocaExame, calculaPrecoImpressaoExame);
        }
        if(!strcmp(cmd, "QUANTIDADE")){
            printf("- QUANTIDADE DE DOCUMENTOS NA FILA: %d\n", quantidadeDocumentosNaFilaImp(f));
        }
        if(!strcmp(cmd, "PRECO")){
            printf("- PRECO TOTAL DA FILA: R$ %.2f\n", precoTotalImpressaoFilaImp(f, preco));
        }
        if(!strcmp(cmd, "FIM")){
            imprimeFilaImp(f);
        }
        if(!strcmp(cmd, "FIM")){
            break;
        }
    }

    desalocaFilaImp(f);
    return 0;
}