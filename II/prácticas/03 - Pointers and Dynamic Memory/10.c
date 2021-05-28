#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define tam 4

typedef struct
{
char *txt;
unsigned int longitud;
} t_texto;

char* f_cargadin();
void f_ingresoycalculo(t_texto*);
int main()
{
    t_texto text;
    f_ingresoycalculo(&text);
    printf("\n%s\n%u",text.txt,text.longitud);
    return 0;
}
char* f_cargadin()
{
    char* texto=NULL;
    int bloque=4;
    texto=malloc(sizeof(char)*bloque);
    if(texto!=NULL)
    {
        char aux,cont=0;
        printf("ingrese el texto:\n");
        do
        {
            aux=getche();
            if(aux=='\r')
            *(texto+cont)='\0';
            else
                *(texto+cont)=aux;
                cont++;
            if(cont>=bloque&&aux!='\r')
            {
                bloque+=tam;
                texto=realloc(texto,sizeof(char)*bloque);
                if(texto==NULL)
                exit(0);
            }
        }while(aux!='\r');
        if (cont!=bloque)
        {
            texto=realloc(texto,sizeof(char)*cont);
            if(texto==NULL)
            exit(0);
        }
    }
    return texto;
    }
void f_ingresoycalculo (t_texto* s)
{
    int x;
    (s->txt)=f_cargadin();
    for(x=0;*(s->txt+x)!='\0';x++);
    s->longitud=x;
    return;
}
