#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
    char dni[10];
    char nombre[100],apellido[100];
    double monto_adeudado;
} t_datos;

char* cargatexto();
int es_igual(char*,char*);
void llenar_arch_refinado(FILE*,FILE*,char*,char*);
int main()
{
    FILE *arch_original=NULL,*arch_refinar=NULL;
    char *nomb_origen=NULL,*nomb_refina=NULL;
    printf("ingrese el nombre del archivo a refinar, con su respectiva extension: \n");
    nomb_origen=cargatexto();
    printf("ingrese el nombre del archivo en el que se guardara la refinacion, con su respectiva extension: \n");
    nomb_refina=cargatexto();
    llenar_arch_refinado(arch_original,arch_refinar,nomb_origen,nomb_refina);
    return 0;
}
void llenar_arch_refinado(FILE *original,FILE *refinado,char *n_origen,char *n_refina)
{
    t_datos s_origen,s_refina;
    int aux;
    fpos_t *posref=NULL;
    posref=malloc(sizeof(fpos_t));
    if(posref==NULL)
        exit(1);
    original=fopen(n_origen,"rb");
    if(original==NULL)
        exit(2);
    refinado=fopen(n_refina,"w+b");
    if(refinado==NULL)
        exit(3);
    while(fread(&s_origen,sizeof(t_datos),1,original)==1)
        {
            fgetpos(refinado,posref);
            rewind(refinado);
            aux=0;
            while(fread(&s_refina,sizeof(t_datos),1,refinado)==1)
                if(es_igual(s_origen.dni,s_refina.dni))
                    {
                        aux=1;
                        break;
                        printf("\n hola");
                    }
            if(aux==0)
                {
                    fsetpos(refinado,posref);
                    fwrite(&s_origen,sizeof(t_datos),1,refinado);
                }
        }
}
int es_igual(char* dni1,char *dni2)
{
    int es,pos;
    for(es=1,pos=0;dni1[pos]!='\0';pos++)
        if(dni1[pos]!=dni2[pos])
            es=0;
    if(es)
        return 1;
    else
        return 0;
}
char* cargatexto()
{
    int pos=0;
    char* txt=NULL;
    txt=malloc(sizeof(char));
    do
    {
        if(txt==NULL)
            exit(1);
        txt=realloc(txt,sizeof(char)*(pos+1));
        *(txt+pos)=getche();
        if(*(txt+pos)=='\r')
            *(txt+pos)='\0';
    }while(*(txt+pos++)!='\0');
    return txt;
}
