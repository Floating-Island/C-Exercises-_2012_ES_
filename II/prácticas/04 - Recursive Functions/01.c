#include <stdio.h>
#include <stdlib.h>

int multR(int,int);
int main()
{
    int a,b;
    printf("ingrese uno y despues otro\n");
    scanf("%d",&a);
    scanf("%d",&b);
    b=multR(a,b);
    printf("\nsu multiplicacion es: %d",b);
    return 0;
}
int multR(int valA,int valB)
{
    int res=valA;
    if(valB==0)
        return 0;
    else
        return res+=multR(valA,valB-1);
}
