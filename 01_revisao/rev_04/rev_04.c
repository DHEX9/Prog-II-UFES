#include <stdio.h>

int main(){
    int num, resto[20] = {0}, i = 0;

    scanf("%d", &num);

    while(num > 0){ 
        resto[i++] = num % 8;
        num /= 8;
    }   
    
    for (int j = i - 1; j >= 0; j--){
        printf("%d", resto[j]);
    }
    
    return 0;
}