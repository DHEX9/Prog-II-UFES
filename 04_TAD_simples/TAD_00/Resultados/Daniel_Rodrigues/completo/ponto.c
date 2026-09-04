#include "ponto.h"
#include <math.h>

/* Funcao cria 
** Retorna um ponto com coordenadas (x,y)
*/
Ponto pto_cria (float x, float y){
    Ponto ponto = {x , y};
    return ponto;
}

/* Funcao acessa x
** Retorna o valor da coordenada x de um ponto
*/
float pto_acessa_x (Ponto p){
    return p.x;
}

/* Funcao acessa y
** Retorna o valor da coordenada x de um ponto
*/
float pto_acessa_y (Ponto p){
    return p.y;
}

/* Funcao atribui x
** Atribui novo valor as coordenada x de um ponto
*/
Ponto pto_atribui_x (Ponto p, float x){
    p.x = x;
    return p;
}

/* Funcao atribui y
** Atribui novo valor as coordenada x de um ponto
*/
Ponto pto_atribui_y (Ponto p, float y){
    p.y = y;
    return p;
}

/* Funcao distancia
** Retorna a distancia entre dois pontos
*/
float pto_distancia (Ponto p1, Ponto p2){
    float dx = (p2.x - p1.x);
    float dy = (p2.y - p1.y);
    return sqrt(dx * dx + dy * dy);
}