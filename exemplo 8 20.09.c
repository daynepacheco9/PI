#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void init_mat(int valor, int *p, int n, int m)
{
    int i,j;
    for (i=0;i<n;i++)
        for (j=0;j<m;j++)
            *(p+i*m+j)=valor;
}

void print_mat(int *p, int n, int m)
{
    int i,j;
    printf("------------------------------------------");
    for (i=0; i <n; i++)
    {
        printf("\n");
        for (j=0; j<m;j++)
        {
        printf("%-5d",*(p+i*m+j));
        }
    printf("\n----------------------------------------");
    
    }

}