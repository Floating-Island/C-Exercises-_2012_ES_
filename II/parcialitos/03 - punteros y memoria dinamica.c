#include <stdio.h>
#include <stdlib.h>

int* funciondinamica(int[],int[]);
int main()
{
    int a[]={3,278,0},b[]={7,8,9,3,12,1,64,72,4,2,0},pos;
    int* fundin=NULL;
    fundin=funciondinamica(a,b);
    if(fundin!=NULL)
        for(pos=0;*(fundin+pos)!=0;pos++)
            printf("%d.",*(fundin+pos));
    free(fundin);
    return 0;
}
int* funciondinamica(int a[],int b[])
{
    int* fun=NULL;int i=0,x,tam=4,bloque=tam;
    fun=malloc(sizeof(int)*bloque);
    if(fun!=NULL)
    {
        for(x=0;a[x]!=0;x++)
        {
            if(i>=bloque)
            {
                bloque+=tam;
                fun=realloc(fun,sizeof(int)*bloque);
                if(fun==NULL)
                {
                    printf("\nno queda mas espacio\n");
                    exit(0);
                }
            }
            if(a[x]%2==0&&a[x]!=0)
                *(fun+i++)=a[x];
        }
         for(x=0;b[x]!=0;x++)
        {
            if(i>=bloque)
            {
                bloque+=tam;
                fun=realloc(fun,sizeof(int)*bloque);
                if(fun==NULL)
                {
                    printf("\nno queda mas espacio\n");
                    exit(0);
                }
            }
            if(b[x]%2==0&&b[x]!=0)
                *(fun+i++)=b[x];
        }
        *(fun+i)=0;
        if(i!=bloque)
        {
            fun=realloc(fun,sizeof(int)*i);
            if(fun==NULL)
            {
                printf("\nno queda mas espacio\n");
                exit(0);
            }
        }
    }
    return fun;
}
