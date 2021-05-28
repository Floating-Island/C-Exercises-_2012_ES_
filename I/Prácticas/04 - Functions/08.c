#include <stdio.h>
#include <stdlib.h>
int carga_char ();
int convertidor (char*,int);
int main()
{
    int numero;
    numero=carga_char();
    printf("\n%d",numero);
    return 0;
}
int carga_char ()
{
    char c[10];
    int a=0,b;
    printf("ingrese un numero, finalice con ENTER:");
    do
    {
        c[a]=getche();
        if (c[a]>=48&&c[a]<=57)
        a++;
    }while(a<9&&c[a]!='\r');
    b=convertidor(c,a);
    return b;
}
int convertidor (char x[10],int b)
{
    int y,c=1,d=0;
b-=1;
for(y=1;y<=b;y++)
c*=10;
for(y=0;y<=b;y++)
{
    d+=(x[y]-48)*c;
    c/=10;
}

    return d;
}

