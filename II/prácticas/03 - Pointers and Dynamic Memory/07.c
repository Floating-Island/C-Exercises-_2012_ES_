#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define tam 5
char* f_cargadin();
int main()
{
    char *texto=NULL;
    texto=f_cargadin();
    printf("\n%s",texto);
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
                exit(2);
            aux=getche();
            if(aux=='\r')
                *(texto+cont)='\0';
            else
                *(texto+cont++)=aux;
        }while(aux!='\r');
    }
    else
    exit(1);
    return texto;
}
