#include <stdio.h>
#include <stdlib.h>
#include <math.h>
unsigned int dividir8(unsigned int);
void mostrarbits(int);
int main()
{
    int num;
    printf("ingrese un numero:\n");
    scanf("%u",&num);
    mostrarbits(num);
    num=dividir8(num);
    mostrarbits(num);
    printf("dividido 8 es: %u",num);
    return 0;
}
unsigned int dividir8(unsigned int x)
{
    int p=0,y;
    for(y=0;y<(x>>3);y++)
    p+=(unsigned int)pow(2,y);
    return (x>>3)&p;
}
void mostrarbits(int numero)
{
    int x;
    for(x=31;x>=0;x--)
    printf("%d",((numero&(int)pow(2,x))>>x)&1);
    printf("\n");
    return;
}
