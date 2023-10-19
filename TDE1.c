#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char digitos[15] ;
    int cpf[11], soma = 0, resto, digito1, digito2;

    printf("Digite o seu CPF(no formato xxx.xxx.xxx-xx):\n");
    scanf("%s",digitos);

    int j = 0;
    

    for (unsigned i=0; i < strlen(digitos); i++)
    {
        if ( digitos[i] >= '0' && digitos[i] <= '9')
        {
            cpf[j] = (int)digitos[i] - '0';
            j++;
        }
    }

    for (int i = 0; i < 9; i++ )
    {
        soma += cpf[i] * (10 - i); 
    }

    resto = soma % 11;

    if (resto < 2) digito1 = 0;
    else digito1 = 11 - resto;

    soma = 0;

    for (int i = 0; i < 10; i++ )
    {
        soma += cpf[i] * (11 - i); 
    }

    resto = soma % 11;

    if (resto < 2) digito2 = 0;
    else digito2 = 11 - resto;

    if (digito1 == cpf[9] && digito2 == cpf[10])
    {
        printf("\nCPF valido!!\n");
    }
    else
    {
        printf("\nCPF invalido!!\n");
    }
}