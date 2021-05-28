#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
    char nombre[100],domicilio[200];
    unsigned int codigo_postal, nro_documento;
    unsigned char edad_sexo;
} t_persona;

char* cargatexto();
void cargaenstruct(char[],int);
t_persona carga();
void appendarchivo(char*);
void binarioacsv(char*,char*);
int es_igual(char[],char[]);
int mismoregistro(char*,char*);
t_persona buscapordocumento(char*,unsigned int);
t_persona* buscaporcpostal(char*,unsigned int);
void imprimir(t_persona);
void imprimirtodo(t_persona*);

int main()
{
    unsigned int documento=0,cp=0;
    int opcion=5;
    do
    {
        printf("\nQue desea hacer?\n1.Añadir registro.\n2.Transformar binario.\n3.Buscar por documento.\n4.Buscar por codigo postal.\n5.Verificar si contienelos mismos registros\n6.Salir.\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            printf("\n Ingrese el nombre del archivo con su respectiva extension: ");
            appendarchivo(cargatexto());
            break;
        case 2:
            printf("\nIngrese el nombre del archivo binario con su extension, luego hacer lo mismo para el archivo csv: ");
            char *arbin,*arcsv;
            arbin=cargatexto();
            arcsv=cargatexto();
            binarioacsv(arbin,arcsv);
            break;
        case 3:
            printf("\nIngrese el numero de documento y a continuacion el nombre del archivo:\n");
            scanf("%u",&documento);
            char *nombrearch=NULL;
                nombrearch=cargatexto();
            printf("\n%-13s:%5s%-15s:%5s%-7s:%5s%-9s:%5s%-4s:%5s%-4s:\n","Nombre","","Domicilio","","Cpostal","","Documento","","Edad","","Sexo");
            imprimir(buscapordocumento(nombrearch,documento));
        break;
        case 4:
            printf("\nIngrese el codigo postal y a continuacion el nombre del archivo:\n");
            scanf("%u",&cp);
            char* nombrearchi=NULL;
            nombrearchi=cargatexto();
            printf("\n%-13s:%5s%-15s:%5s%-7s:%5s%-9s:%5s%-4s:%5s%-4s:\n","Nombre","","Domicilio","","Cpostal","","Documento","","Edad","","Sexo");
            imprimirtodo(buscaporcpostal(nombrearchi,cp));
        break;
        case 5:
            printf("\nIngrese el nombre del primer archivo:\n");
            char* nombrearch1=NULL;
            nombrearch1=cargatexto();
            printf("\nIngrese el nombre del segundo archivo:\n");
            char* nombrearch2=NULL;
            nombrearch2=cargatexto();
            printf("\nLos archivos %s el mismo contenido",(mismoregistro(nombrearch1,nombrearch2)? "tienen":"no tienen"));
        }
    }while(opcion!=6);
    return 0;
}
char* cargatexto()
{
    int pos=0;
    char *txt=NULL;
    txt=malloc(sizeof(char));
    if(txt==NULL)
        exit(0);
    do
    {
        txt=realloc(txt,sizeof(char)*(pos+1));
        if(txt==NULL)
            exit(0);
        *(txt+pos)=getche();
        if(*(txt+pos)=='\r')
            *(txt+pos)='\0';
    }while(*(txt+pos++)!='\0');
    return txt;
}
void cargaenstruct(char texto[],int tamax)
{
    int pos=0;
    do
    {
        texto[pos]=getche();
        if(texto[pos]=='\r')
            texto[pos]='\0';
    }while(texto[pos++]!='\0'&&pos<(tamax-1));
    if(tamax<pos)
        texto[pos]='\0';
}
t_persona carga()
{
    t_persona per;
    int edad=0;
    printf("\nIngrese el nombre: ");
    cargaenstruct(per.nombre,100);
    printf("\nIngrese el domicilio: ");
    cargaenstruct(per.domicilio,200);
    printf("\nIngrese el codigo postal: ");
    scanf("%u",&(per.codigo_postal));
    printf("\n Ingrese el número de documento: ");
    scanf("%u",&(per.nro_documento));
    do
    {
        if(edad>64)
            printf("\n ERROR, LA EDAD DEBE SER MENOR A LOS 64 AÑOS");
       printf("\nIngrese la edad: ");
       scanf("%d",&edad);
    }while(edad>64);
    per.edad_sexo=(char)edad;
    printf("ingrese sexo mascuino o femenino (m o f): ");
    per.edad_sexo=per.edad_sexo^(((getche()=='m')? 1:0)<<8);
    return per;
}
void appendarchivo(char *nombrear)
{
    FILE *archivo=NULL;
    archivo=fopen(nombrear,"ab");
    t_persona persona=carga();
    fwrite(&persona,sizeof(t_persona),1,archivo);
    fclose(archivo);
}
void binarioacsv (char* bin,char* csv)
{
    t_persona origen;
    FILE *arbin=NULL,*arcsv=NULL;
    arbin=fopen(bin,"rb");
    if(arbin==NULL)
        exit(2);
    arcsv=fopen(csv,"w");
    while(fread(&origen,sizeof(t_persona),1,arbin)==1)
        fprintf(arcsv,"%s,%s,%u,%u\n",origen.nombre,origen.domicilio,origen.codigo_postal,origen.edad_sexo);
        fclose(arbin);
        fclose(arcsv);
}
int es_igual(char texto1[],char texto2[])
{
    int posicion;
    for(posicion=0;texto1[posicion]!='\0';posicion++)
        if(texto1[posicion]!=texto2[posicion]||texto1[posicion+1]!=texto2[posicion+1])
            return 0;
    return 1;
}
int mismoregistro(char *arcbin1,char* arcbin2)
{
    int aux;
    t_persona registroprimero,registrosegundo;
    FILE *auno=NULL,*ados=NULL;
    auno=fopen(arcbin1,"rb");
    if(auno==NULL)
        exit(3);
    ados=fopen(arcbin2,"rb");
    if(ados==NULL)
        exit(4);
    while(fread(&registroprimero,sizeof(t_persona),1,auno)==1)
    {
        aux=0;
        while(fread(&registrosegundo,sizeof(t_persona),1,ados)==1)
            if(registroprimero.edad_sexo==registrosegundo.edad_sexo)
                if(registroprimero.nro_documento==registrosegundo.nro_documento)
                    if(es_igual(registroprimero.nombre,registrosegundo.nombre))
                        if(es_igual(registroprimero.domicilio,registrosegundo.domicilio))
                            {
                                aux=1;
                                break;
                            }
        if(aux==0)
            {
                fclose(auno);
                fclose(ados);
                return 0;
            }
    }
    while(fread(&registrosegundo,sizeof(t_persona),1,ados)==1)
    {
        aux=0;
        while(fread(&registroprimero,sizeof(t_persona),1,auno)==1)
            if(registroprimero.edad_sexo==registrosegundo.edad_sexo)
                if(registroprimero.nro_documento==registrosegundo.nro_documento)
                    if(es_igual(registroprimero.nombre,registrosegundo.nombre))
                        if(es_igual(registroprimero.domicilio,registrosegundo.domicilio))
                            {
                                aux=1;
                                break;
                            }
        if(aux==0)
            {
                fclose(auno);
                fclose(ados);
                return 0;
            }
    }
    fclose(auno);
    fclose(ados);
    return 1;
}
t_persona buscapordocumento(char* nombrearc,unsigned int doc)
{
    t_persona registro;
    t_persona *reg=NULL;
    FILE* archivo=NULL;
    archivo=fopen(nombrearc,"rb");
    if(archivo==NULL)
        exit(4);
    while(fread(&registro,sizeof(t_persona),1,archivo)==1)
        if(registro.nro_documento==doc)
            {
                fclose(archivo);
                return registro;
            }
    fclose(archivo);
    return *reg;
}
t_persona* buscaporcpostal(char* nombre,unsigned int cp)
{
    int pos=1;
    t_persona *arregistro=NULL,aux;
    FILE *arc=NULL;
    arc=fopen(nombre,"rb");
    if(arc==NULL)
        exit(5);
    arregistro=malloc(sizeof(t_persona));
    if(arregistro==NULL)
        exit(6);
    while(fread(&aux,sizeof(t_persona),1,arc)==1)
        if(aux.codigo_postal==cp)
        {
            arregistro=realloc(arregistro,sizeof(t_persona)*(pos));
            *(arregistro+pos++)=aux;
        }
    arregistro=realloc(arregistro,sizeof(t_persona)*(pos));
    aux.nro_documento=0;
    *(arregistro+pos)=aux;
    fclose(arc);
    return arregistro;
}
void imprimir(t_persona registro)
{
    int edad;
    char sexo;
    edad=(double)(registro.edad_sexo<<1)/2;
    sexo=(registro.edad_sexo>>7)? 'm':'f';
    printf("%-13s%5s%-15s%5s%-7u%5s%-9u%5s%-4d%5s%-4c",registro.nombre,"",registro.domicilio,"",registro.codigo_postal,"",registro.nro_documento,"",edad,"",sexo);
}
void imprimirtodo(t_persona *registros)
{
    int pos;
    for(pos=0;(registros+pos)->nro_documento!=0;pos++)
        imprimir(*(registros+pos));
}
