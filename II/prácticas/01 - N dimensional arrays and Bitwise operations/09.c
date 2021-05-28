#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
char f_shiftd_seguro(char,int);
int main()
{
    char a,c;
    int b;
    printf("ingrese la letra:");
    a=getche();
    printf("\ningrese el numero de corrimientos a hacer:");
    scanf("%d",&b);
    printf("%d",c=f_shiftd_seguro(a,b));
    return 0;
}
char f_shiftd_seguro(char a,int x)
{
    int c;
    char b=0;
    a=a>>x;
    for(c=0;c<8-x;c++)
    b+=pow(2,c);
    return a&b;
}

