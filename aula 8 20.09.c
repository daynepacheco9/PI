#include <stdio.h>
#include <stdlib.h> /* malloc(); exit()*/

int main(){
    short *p; /*Tamanho short: 2 bytes*/
    short a=5;

    p = (short*)malloc(a*sizeof(short));
    /*Cast (short*): p aponta para a regiao de inteiros curtos*/    
    if (!p){/*!p é verdade se p é nulo */
        printf(("Erro : Memoria Insuficiente!"));
        exit(EXIT_FAILURE);
        /*ou exit(1): termina sem sucesso */
    }
}  