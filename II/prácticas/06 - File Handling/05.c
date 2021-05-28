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

int main()
{
    FILE *archivo=NULL;
    t_datos buffer;
    printf("ingrese el nombre del archivo, con su respectiva extension: \n");
    archivo=fopen(cargatexto(),"rb");
    if(archivo==NULL)
        exit(1);
    printf("%-12s%5s%-13s%5s%-14s%5sDNI:\n","Nombre:","","apellido:","","Monto adeudado:","");
    while(fread(&buffer,sizeof(t_datos),1,archivo)==1)
    {
        printf("%-12s%5s%-13s%5s%-14.3lf%5s%-8s\n",buffer.nombre,"",buffer.apellido,"",buffer.monto_adeudado,"",buffer.dni);
    }
    fclose(archivo);
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
