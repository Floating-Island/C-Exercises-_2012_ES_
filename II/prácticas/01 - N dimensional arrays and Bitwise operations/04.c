#include <stdio.h>
#include <stdlib.h>
#define tam 15
void crear_rombo (char [][tam],int);
void imprimir(char [][tam]);
int main()
{
    int t,i,j;
    char r[tam][tam];
    for(i=0;i<tam;i++)
    for(j=0;j<tam;j++)
    r[i][j]=' ';
    do
    {
        printf("ingrese la altura del rombo:\n");
    scanf("%d",&t);
    if(t%2==0||t<1|t>tam)
    printf("\nDebe ser impar mayor o igual que 1\n");
    }while(t%2==0||t<1||t>tam);
    printf("\n");
    crear_rombo(r,t);
    imprimir(r);
    return 0;
}
void crear_rombo(char m[tam][tam],int h)
{
    int esp,ast,fila,col,cr=h/2+1;
    for(fila=0;fila<cr;fila++)
    {
        col=0;
        for(esp=0;esp<(h/2-fila);esp++,col++)
            m[fila][col]=' ';
        for(ast=0;ast<(1+2*fila);col++,ast++)
            m[fila][col]='*';
    }
    for(col=0;fila<=h+2;fila++,col=0)
        {
            for(esp=0;esp<(fila-h/2);col++,esp++)
                m[fila][col]=' ';
            for(ast=0;ast<(h-esp*2);col++,ast++)
                m[fila][col]='*';
        }
    return;
}
void imprimir(char x[tam][tam])
{
    int f,c;
    for(f=0;f<tam;f++)
    {
    for(c=0;c<tam;c++)
    printf("%c",x[f][c]);
    printf("\n");
    }
    return;
}
