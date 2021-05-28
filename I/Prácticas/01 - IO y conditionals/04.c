#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d,e,f;
    printf("ingrese un numero de 5 digitos\n");
    scanf("%d",&f);
    a= f/10000;
    b=(f-a*10000)/1000;
    c=(f-a*10000-b*1000)/100;
    d=(f-a*10000-b*1000-c*100)/10;
    e=(f-a*10000-b*1000-c*100-d*10);
    printf("%d-%d-%d-%d-%d",a,b,c,d,e);
    return 0;
}
