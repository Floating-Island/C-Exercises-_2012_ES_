#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int f_charaint(char,char,char,char);
int main()
{
    char a,b,c,d;
    int x;
    printf("ingrese los chars\n");
    a=getche();
    b=getche(),
    c=getche();
    d=getche();
    printf("\nel resultante es: %d",x=f_charaint(a,b,c,d));

    return 0;
}
int f_charaint(char a,char b,char c,char d)
{
    int x=0,y;
    char n[4]={a,b,c,d};
    for(y=0;y<4;y++)
    {
        x=x|n[y];
        if(y<3)
        x=x<<8;
    }
    return x;
}
