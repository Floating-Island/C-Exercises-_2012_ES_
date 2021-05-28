#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char* cargatexto();
void creaarchivo(FILE*);
void leearchivoycuenta(FILE*);

int main()
{
    FILE *proto=NULL;
    creaarchivo(proto);
    leearchivoycuenta(proto);
    return 0;
}
void creaarchivo(FILE* proto)
{
    char* txt=NULL;
    proto=fopen("texto.txt","w");
    if(proto==NULL)
        exit(1);
    fputs(txt=cargatexto(),proto);
    fclose(proto);
}
void leearchivoycuenta(FILE* arc)
{
char txt;int chara=0;int cont=0;
    arc=fopen("texto.txt","r");
    rewind(arc);
    printf("\n");
    while((chara=fgetc(arc))!=EOF)
    {
        txt=(char)chara;
        printf("%c",txt);
        cont++;
    }
    fclose(arc);
    printf("\ntiene %d caracteres",cont);
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
                *(txt+pos)='\n';
        }while(*(txt+pos++)!='\n');
        txt=realloc(txt,sizeof(char)*pos);
        *(txt+pos)='\0';
        return txt;
}
