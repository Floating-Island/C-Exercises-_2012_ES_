#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,x1=1,x2=0;
    printf("ingrese numeros decimales enteros\n");
    scanf("%d",&x);
    while(x<0)
    {
        printf("ingrese numeros decimales enteros psitivos\n");
        scanf("%d",&x);
    }
 while (x>0)
 {
 x2=x2+(x%2)*x1;
 x1=x1*10;
 x=x/2;
 }
 printf("%d",x2);
 return 0;
}
