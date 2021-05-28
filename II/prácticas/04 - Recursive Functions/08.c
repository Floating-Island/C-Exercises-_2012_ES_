#include <stdio.h>
#include <stdlib.h>
int potencia(int,int);
int main()
{
    int num, cantidad;
    printf("ingrese numero\n");
    scanf("%d",&num);
    printf("ingrese el exponente: \n");
    scanf("%d",&cantidad);
    printf("\n el resultado es: %d",num=potencia(cantidad,num));
    return 0;
}
int potencia(int nveces,int numero)
{
    if(nveces!=0)
    return numero*=potencia(nveces-1,numero);
    else
    return 1;
}
