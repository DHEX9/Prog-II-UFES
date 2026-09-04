#include <stdio.h>

int value(char c){
    if(c >= '0' && c <= '9'){
        return c - '0';
    }
    else if(c >= 'A' && c <= 'Z'){
        return c - 'A' + 10;
    }
    return c - 'a' + 36;
}

int main(){
    char rotulos[1000];
    int count[62] = {0};
    int limite, encontrou = 0;

    scanf("%d", &limite);
    scanf("%s", &rotulos);

    for(int i = 0; rotulos[i] != '\0'; i++){
        count[value(rotulos[i])]++;
    }
    
    // 0 - 9
    for(int i = 0; i < 10; i++){
        if(count[i] > limite){
            printf("%c: %d\n", i + '0', count[i]);
            encontrou = 1;
        }
    }

    // A - Z
    for(int i = 10; i < 36; i++){
        if(count[i] > limite){
            printf("%c: %d\n", i + 'A' - 10, count[i]);
            encontrou = 1;
        }
    }

    // a - z
    for(int i = 36; i <= 62; i++){
        if(count[i] > limite){
            printf("%c: %d\n", i + 'a' - 36, count[i]);
            encontrou = 1;
        }
    }
    
    if(!encontrou){
        printf("NENHUM\n");
    }

    return 0;
}