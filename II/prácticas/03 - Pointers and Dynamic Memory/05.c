#include <stdio.h>
#include <stdlib.h>
typedef struct{
int a,b,c,d;
} t_cuatro;
void f_orden (t_cuatro*);
int main()
{
    t_cuatro str;
    str.a=8;
    str.b=0;
    str.c=7;
    str.d=3;
    f_orden(&str);
    printf("%d %d %d %d",str.a,str.b,str.c,str.d);
    return 0;
}
void f_orden (t_cuatro *strptr)
{
    int *aptr[4]={&(strptr->a),&(strptr->b),&(strptr->c),&(strptr->d)};
    int x,y,aux;
    for(x=0;x<4;x++)
        for(y=x+1;y<4;y++)
            if(*aptr[x]>*aptr[y])
            {
                aux=*aptr[x];
                *aptr[x]=*aptr[y];
                *aptr[y]=aux;
            }
    return;
}
