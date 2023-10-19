#include <stdio.h>

int main(){
int num=55, valor; int *p;
p =&num;
valor = *p;
printf("Valor1=%d\n",valor);
printf("Valor2=%d\n",*p);
*p = *p+3; 
printf("Valor3=%d\n",*p);
(*p)--;
printf("Valor4=%d\n", *p);
valor = num - *p;
printf("Valor5=%d\n", valor);


}