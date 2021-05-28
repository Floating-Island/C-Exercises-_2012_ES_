#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    printf("ingrese un numero\n");
    scanf("%d",&a);
    printf("ingrese otro numero\n");
    scanf("%d", &b);
    c=a%10+b/10*10;
    printf("la composicion de la unidad de la primera con la decena del segundo es\n %d",c);
    return 0;
}
