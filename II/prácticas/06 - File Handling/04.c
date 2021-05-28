#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
    char dni[10];
    char nombre[100],apellido[100];
    double monto_adeudado;
} t_datos;
t_datos cargastruct();
char* cargatexto();
void cargatextostruct(char[],int);
int main()
{
    FILE *archivo=NULL;
    t_datos aux;
    printf("ingrese el nombre del archivo, con su respectiva extension: \n");
    archivo=fopen(cargatexto(),"ab");
    printf("\n ingrese los datos requeridos, para finalizar ingrese 0 en el dni.\n");
    for(aux=cargastruct();aux.dni[0]!='0';aux=cargastruct())
        fwrite(&aux,sizeof(t_datos),1,archivo);
    fclose(archivo);
    return 0;
}
t_datos cargastruct()
{
    t_datos*str=NULL;
    str=malloc(sizeof(t_datos));
    if(str==NULL)
        exit(0);
    printf("\n ingrese el nombre: ");
    cargatextostruct(str->nombre,100);
    printf("\n ingrese el apellido: ");
    cargatextostruct(str->apellido,100);
    printf("\n ingrese el dni: ");
    cargatextostruct(str->dni,10);
    printf("\n ingrese el monto adeudado: $ ");
    scanf("%lf",&(str->monto_adeudado));
    return *str;
}
void cargatextostruct(char texto[],int tamax)
{
    int posicion=0;
    do
    {
        texto[posicion]=getche();
        if(texto[posicion]=='\r')
            texto[posicion]='\0';
    }while(texto[posicion++]!='\0'&&posicion<tamax-2);
    if(tamax<posicion)
        texto[posicion]='\0';
}
char* cargatexto()
{
    int pos=0;
    char* txt=NULL;
    txt=malloc(sizeof(char));
    do
    {
    if (txt==NULL)
        exit(1);
        txt=realloc(txt,sizeof(char)*(pos+1));
        *(txt+pos)=getche();
        if(*(txt+pos)=='\r')
            *(txt+pos)='\0';
    }while(*(txt+pos++)!='\0');
    return txt;
}
