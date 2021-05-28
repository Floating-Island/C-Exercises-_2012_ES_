#include <stdio.h>
#include <stdlib.h>
int entpos (int);
int base (int);
int cambiobase (int,int);
int main()
{
    int a,b,c;
    a=entpos (a);
    b=base (b);
    c=cambiobase (a,b);
    printf("%d",c);
    return 0;
}

int entpos (x)
{
    printf("ingrese un numero positivo\n");
    do
    {
      scanf("%d",&x);
      if (x<=0)
      printf("error, ingrese numero entero positivo");
    }while(x<=0);
    return x;
}
int base (r)
{
    do
    {
        r=entpos (r);
        if(r<2||r>9)
        printf("debe ser entre 2 y 9");
    }while (r<2||r>9);
    return r;
}
int cambiobase (p,s)
{
    int x2=0,x1=1;
     while (p>0)
 {
 x2=x2+(p%s)*x1;
 x1=x1*10;
 p=p/s;
 }
 return x2;
}
