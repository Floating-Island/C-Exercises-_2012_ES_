#include <stdio.h>
#include <stdlib.h>
void f_cambio(int*,int*);
int main()
{
    int x,y;
    printf("ingrese un numero y despues ingrese otro:\n");
    scanf("%d",&x);
    scanf("%d",&y);
    f_cambio(&x,&y);
    printf("Al revés quedan : %d,%d",x,y);
    return 0;
}
void f_cambio(int* a,int* b)
{
int x;
x=*a;
*a=*b;
*b=x;
return;
}
