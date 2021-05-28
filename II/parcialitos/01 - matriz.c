#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define CANT_COLORES 3
int menu();
void cargar_colores(char[][15],int [][3]);
void mostrar_colores(char[][15],int[][3]);
void hay_primarios(int [][3]);
int main()
{
    char colores[CANT_COLORES][15];
    int codigos_rva[CANT_COLORES][3];
    int op;
    do
    {
        op=menu();
        switch(op)
        {
            case 1:
            cargar_colores(colores,codigos_rva);
            break;
            case 2:
            mostrar_colores(colores,codigos_rva);
            break;
            case 3:
            hay_primarios(codigos_rva);
            break;
            default:
            break;
        }
    }while(op>=1&&op<=3);
    return 0;
}
int menu()
{
    int a;
    printf("\n ingrese una opcion:\n1_cargar los colores\n2_Mostrar los colores\n3_Mostrar cantidad de primarios\n");
    scanf("%d",&a);
    return a;
}
void cargar_colores(char nombre[CANT_COLORES][15],int coeficientes[CANT_COLORES][3])
{
    int x,y,z;
    char colores[3][6]={{"rojo"},{"verde"},{"azul"}};
    for(x=0;x<CANT_COLORES;x++)
    {
        printf("\ningrese el nombre del %d color: ",x+1);
        y=0;
        do
        {
            nombre[x][y]=getche();
            if(nombre[x][y]!='\r')
            y++;
        }while(y<14&&nombre[x][y]!='\r');
        nombre[x][y]='\0';
        for(y=0;y<3;y++)
        {
            printf("\ningrese el coeficiente del color ");
            for(z=0;colores[y][z]!='\0';z++)
            printf("%c",colores[y][z]);
            printf(": ");
            scanf("%d",&coeficientes[x][y]);
        }
    }
    return;
}
void mostrar_colores(char nomb[CANT_COLORES][15],int coef[CANT_COLORES][3])
{
    int x,y;
    printf("%-15s%5s%8s%10s","Color","Rojo","Verde","Azul");
    for (x=0;x<CANT_COLORES;x++)
        {
            printf("\n");
            for(y=0;nomb[x][y]!='\0';y++)
            printf("%c",nomb[x][y]);
            for(y=0;y<3;y++)
            printf("%10d",coef[x][y]);

        }
        return;
}
void hay_primarios(int c[CANT_COLORES][3])
{
    int x,y,cantprim=0,contcoef=0;
    for(x=0;x<CANT_COLORES;x++)
    {
      for(y=0;y<3;y++)
    {
        if(c[x][y]==255)
        contcoef++;
        if(c[x][y]!=0&&c[x][y]!=255)
        contcoef--;

    }
    if (contcoef==1)
    cantprim++;
    contcoef=0;
    }
    printf("\nSe han ingresado %d colores primarios\n",cantprim);
    return;
}
