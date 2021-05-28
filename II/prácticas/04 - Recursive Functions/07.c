#include <stdlib.h>
#include <stdio.h>

void imprimir_combinaciones(int n);
void armar_comb(char *p,  int t);
void imprimir_rev(char *s);

int main()
{
    int t;
    printf("ingrese un numero:\n");
    scanf("%d",&t);
    imprimir_combinaciones(t);
    return 0;
}

void imprimir_combinaciones(int n)
{
    char *b;
    b = malloc(sizeof(char)*(n+1));
    *(b+n)='\0';
    armar_comb(b, n);
    free(b);
}

void armar_comb(char * p,  int t)
{
    char x;
    if(t>0)
        for(x='a';x<='z';x++)
        {
            *(p+(t-1))=x;
            armar_comb(p,t-1);
        }
    else
        imprimir_rev(p);
}

void imprimir_rev(char *s)
{
    if(*s!='\0')
    {
        imprimir_rev(s+1);
        printf("%c", *s);
    }
    else
        printf("\n");
}
