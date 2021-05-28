#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void generador (int);
void informe(int*,int);
int validar();
int main()
{
    int r;
    srand(time(NULL));
    printf("ingrese un valor no mayor que 100\n");
    r=validar();
    generador(r);
    return 0;
}
int validar()
{
    int m;
    scanf("%d",&m);
    while(m>100)
    {
        printf("error");
        scanf("%d",&m);
    }
    return m;
}
void generador (int a)
{
    int y,x[100];
    for (y=0;y<a;y++)
        {
            x[y]=rand()%36;
            printf("%d-",x[y]);
        }
        informe (x,y);
        return;
}
void informe(int b[100],int e)
{
    int p,v,c=0,d;
    for(p=0;p<e;p++)
    {
        for(v=0;v<e;v++)
        {
            if(b[p]==b[v])
            {
                c+=1;
                d=b[p];
                b[v]=39;
                b[p]=d;
            }
        }
        if(b[p]!=39)
        printf("\nel numero %d salio %d veces(%d%%)",b[p],c,(c*100)/e);
        c=0;
    }
    return;
}
