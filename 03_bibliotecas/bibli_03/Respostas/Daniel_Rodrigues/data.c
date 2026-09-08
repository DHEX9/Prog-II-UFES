#include <stdio.h>
#include "data.h"

int diasMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char nomeMes[][10] = {"", "Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
/**
 * @brief Verifica se uma data é válida.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @return int Retorna 1 se a data é válida e 0 caso contrário.
 */
int verificaDataValida(int dia, int mes, int ano){
    if((dia >= 1 && dia <= diasMes[mes]) && (mes >= 1 && mes <= 12) && ano > 0){
        return 1;
    }

    return 0;
}

/**
 * @brief Imprime o nome do mês por extenso.
 * 
 * @param mes Mês a ser impresso.
 */
void imprimeMesExtenso(int mes){
    if((mes >= 1 && mes <= 12)){
        printf("%s\n", nomeMes[mes]);
    }
}

/**
 * @brief Imprime a data por extenso.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeDataExtenso(int dia, int mes, int ano){
    if((dia >= 1 && dia <= diasMes[mes]) && (mes >= 1 && mes <= 12) && ano > 0){
        printf("%02d de %s de %d\n", dia, nomeMes[mes], ano);
    }
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param ano Ano a ser verificado.
 * @return int Retorna 1 se o ano é bissexto e 0 caso contrário.
 */
int verificaBissexto(int ano){
    if((ano % 4 == 0) && ((ano % 100 != 0) || (ano % 100 == 0 && ano % 400 == 0))){
        return 1;
    }
    return 0;
}

/**
 * @brief Calcula o número de dias de um mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias do mês.
 */
int numeroDiasMes(int mes, int ano){
    if(verificaBissexto(ano)){
        diasMes[2]++;
    }

    return diasMes[mes];
}

/**
 * @brief Compara duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna 1 se a primeira data é maior que a segunda, -1 se a primeira data é menor que a segunda
 * e 0 se as datas são iguais.
 * A data ser "maior" significa que ela está mais no futuro.
 */
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){

    if(ano1 > ano2) return 1;
    if(ano1 < ano2) return -1;
    
    if(mes1 > mes2) return 1;
    if (mes1 < mes2) return -1;
    
    if(dia1 > dia2) return 1;
    if(dia1 < dia2) return -1;

    return 0;       
}


/**
 * @brief Calcula o número de dias até o mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias até o mês.
*/
int calculaDiasAteMes(int mes, int ano){
    int dias = 0;

    if(verificaBissexto(ano)){
        diasMes[2]++;   
    }

    for(int i = 0; i < mes; i++){
        dias += diasMes[i];
    }

    if(verificaBissexto(ano)){
        diasMes[2]--;   
    }

    return dias;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna o número de dias de diferença entre as datas.
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    int aux, total = 0;
    
    if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) > 0){
        aux = dia1; dia1 = dia2; dia2 = aux;
        aux = mes1; mes1 = mes2; mes2 = aux;
        aux = ano1; ano1 = ano2; ano2 = aux;
    }    

    int diaAno1 = calculaDiasAteMes(mes1, ano1) + dia1;
    int diaAno2 = calculaDiasAteMes(mes2, ano2) + dia2;

    if(ano1 == ano2){
        return diaAno2 - diaAno1;
    }

    if(verificaBissexto(ano1)){
        total = 366 - diaAno1;
    }
    else{
        total = 365 - diaAno1;
    }
    

    for(int i = ano1 + 1; i < ano2; i++){
        
        if(verificaBissexto(i)){
            aux = 366;
        }
        else{
            aux = 365;
        }
        total += aux;
    }

    total += diaAno2;
    
    return total;
}