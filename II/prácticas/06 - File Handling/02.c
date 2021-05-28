#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char* cargatexto();
char* cargatextoAR();
void creaarchivo(FILE*);
int main()
{
    FILE *arch=NULL;
    creaarchivo(arch);
    return 0;
}
void creaarchivo(FILE* arc)
{
    printf("Ingrese el nombre para el archivo con su respectiva extensión: ");
    arc=fopen(cargatexto(),"w");
    if(arc==NULL)
        exit(1);
    printf("\n");
    fputs(cargatextoAR(),arc);
    fclose(arc);
}
char* cargatexto()
{
    char *txt=NULL;int pos=0;
    txt=malloc(sizeof(char));
    if(txt!=NULL)
        do
        {
            txt=realloc(txt,sizeof(char)*(pos+1));
            if(txt==NULL)
                exit(1);
            *(txt+pos)=getche();
            if(*(txt+pos)=='\r')
                *(txt+pos)='\0';
        }while(*(txt+pos++)!='\0');
        return txt;
}
char* cargatextoAR()
{
    char *txt=NULL;int pos=0;
    txt=malloc(sizeof(char));
    if(txt!=NULL)
        do
        {
            txt=realloc(txt,sizeof(char)*(pos+1));
            if(txt==NULL)
                exit(1);
            *(txt+pos)=getche();
        }while((*(txt+pos-1)!='\r')&&(*(txt+pos++)!='\r'));
        txt=realloc(txt,sizeof(char)*pos);
        *(txt+pos)='\0';
        return txt;
}
