#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void carga_ar(int*);
void maximo(int*);
void minimo(int*,int);
int main()
{
 int ar[100],y;
 srand(time(NULL));
 carga_ar(ar);
 for(y=0;y<100;y++)
 printf("%d-",ar[y]);
 maximo(ar);

    return 0;
}
void carga_ar(int v[100])
{
    int x;
    for (x=0;x<100;x++)
    v[x]=rand()%100 +1;
    return;
}
void maximo(int x[100])
{
    int a,b=1;
    for (a=0;a<100;a++)
    if(x[a]>b)
    b=x[a];
    printf("\nmaximo es %d",b);
    minimo (x,b);
    return;
}
void minimo(int a[100],int z)
{
    int q;
    for(q=0;q<100;q++)
    if(a[q]<z)
    z=a[q];
    printf("\nminimo es %d",z);
    return;
}
