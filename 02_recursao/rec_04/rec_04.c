#include <stdio.h>
#include <string.h>

int palindromo(char string[], int tamanho, int i){
    if(string[i] == '\0'){
        return 0;
    }

    if(string[i] == string[tamanho - i]){
        return palindromo(string, tamanho, i + 1);
    }
    
    return 1;
}

int main(){

    char palavra[1001];

    while(scanf("%1000s", palavra) == 1){
        if(!palindromo(palavra, strlen(palavra) - 1, 0)){
            printf("SIM\n");
        }
        else{
            printf("NAO\n");
        }
    }
    return 0;
}