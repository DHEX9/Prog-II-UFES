#include <stdio.h>

void imprimeInvertido(char string[], int i){
    if(string[i] == '\0'){
        return;
    }

    imprimeInvertido(string, i + 1);
    printf("%c", string[i]);
}

void invertePorPalavra(char string[]){
    imprimeInvertido(string, 0);
}

int main(){
    char string[1001];
    while(scanf("%1000s", string) == 1){
        invertePorPalavra(string);
        printf(" ");
    }
    
    return 0;
}