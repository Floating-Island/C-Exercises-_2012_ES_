#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define tam 4
typedef struct
{
    char* txt;
    unsigned int longitud;
} t_texto;

char* f_cargadin();
void f_ingresoycalculo(t_texto*);
t_texto* f_cargafrases();
void f_ordenafrases(t_texto*);
void f_imprimefrase(t_texto*);
void f_impfrases(t_texto*);
int main()
{
    t_texto* frases;
    frases=f_cargafrases();
    printf("\nlisto");
    f_ordenafrases(frases);
    printf("\nlisto");
    f_impfrases(frases);
    return 0;
}

char* f_cargadin()
{
    char* txt=NULL;
    int cont=0;
    txt=malloc(sizeof(char));
    if(txt!=NULL)
    do
    {
        txt=realloc(txt,sizeof(char)*(cont+1));
        if(txt==NULL)
            exit(0);
        if((*(txt+cont)=getche())=='\r')
            *(txt+cont)='\0';
    }while(*(txt+cont++)!='\0');
    return  txt;
}
void f_ingresoycalculo (t_texto* s)
{
    int x;
    (*s).txt=f_cargadin();
    for(x=0;*(s->txt+x)!='\0';x++);
    s->longitud=x;
    return;
}
t_texto* f_cargafrases ()
{
    t_texto* frases=NULL;
    int pos=0;
    frases=malloc(sizeof(t_texto));
    if(frases!=NULL)
    {
    do
    {
        frases=realloc(frases,sizeof(t_texto)*(pos+1));
        if(frases==NULL)
            exit(0);
        f_ingresoycalculo(frases+sizeof(t_texto)*pos);
            printf("\n%s\n",(frases+sizeof(t_texto)*pos)->txt);
        if((frases+sizeof(t_texto)*pos)->longitud==0)
            (frases+sizeof(t_texto)*pos)->txt=NULL;
    }while((frases+sizeof(t_texto)*pos++)->txt!=NULL);
    }
    return frases;
}
void f_ordenafrases(t_texto* aordenar)
{
    int pos1,pos2,posa;
    t_texto aux;
    for(pos1=0;(aordenar+sizeof(t_texto)*pos1)->longitud!=0;pos1++)
        for(pos2=pos1+1;(aordenar+sizeof(t_texto)*pos2)->longitud!=0;pos2++)
        {
            for(posa=0;*((aordenar+sizeof(t_texto)*pos2)->txt+sizeof(char)*posa)!='\0'&&*((aordenar+sizeof(t_texto)*pos1)->txt+sizeof(char)*posa)!='\0';posa++)
            if(*((aordenar+sizeof(t_texto)*pos2)->txt+sizeof(char)*posa)>*((aordenar+sizeof(t_texto)*pos2)->txt+sizeof(char)*posa))
            {
                aux=*(aordenar+sizeof(t_texto)*pos1);
                *(aordenar+sizeof(t_texto)*pos1)=*(aordenar+sizeof(t_texto)*pos2);
                *(aordenar+sizeof(t_texto)*pos2)=aux;
            }
        }
    return;
}
void f_imprimefrase(t_texto* fr)
{
    printf("\n%s",fr->txt);
}
void f_impfrases(t_texto* frase)
{
    int pos;
    for(pos=0;(frase+sizeof(t_texto)*pos)->longitud!=0;pos++)
        f_imprimefrase(frase+sizeof(t_texto)*pos);
}
