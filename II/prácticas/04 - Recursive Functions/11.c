#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char* f_cargadin();
unsigned int contar_vocales(char*);

int main()
{
    char* txt;
    txt=f_cargadin();
    printf("\nHay %d vocal/es",contar_vocales(txt));
    return 0;
}
char* f_cargadin()
{
    char* texto=NULL;
    texto=malloc(sizeof(char));
    if(texto!=NULL)
    {
        char aux;
        int cont=0;
        printf("ingrese el texto:\n");
        do
        {
            texto=realloc(texto,sizeof(char)*(cont+1));
            if(texto==NULL)
                exit(0);
            aux=getche();
            if(aux=='\r')
                *(texto+cont)='\0';
            else
                *(texto+cont++)=aux;
        }while(aux!='\r');
    }
    return texto;
}
unsigned int contar_vocales(char* l)
{
    if(*l!='\0')
    {
        if(*l=='a'||*l=='e'||*l=='i'||*l=='o'||*l=='u')
            return 1+contar_vocales(l+1);
        else
            return contar_vocales(l+1);
    }
    else
        return 0;
}

