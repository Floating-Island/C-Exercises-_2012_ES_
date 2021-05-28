#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void carga_nombres(char [][25]);
void imprimir_nombres(char [][25]);
void opcion(char [][25]);
void ordenar_nombres1(char [][25] );
void ordenar_nombres2(char [][25]);
void ordenar_nombres3(char[][25]);
void cambio(char [][25],int,int);
#define numero 4
int main()
{
    char nombres[numero][25];
    carga_nombres(nombres);
    opcion(nombres);
    return 0;
}
void imprimir_nombres(char n[numero][25])
{
    int x,y;
    for(x=0;x<numero;x++)
    {
          for(y=0;n[x][y]!='\0';y++)
    printf("%c",n[x][y]);
    printf("\n");
    }
return;
}
void opcion(char n[numero][25])
{
        int eleccion;
    printf("\nelija una opcion:\n1_Ordenar por primera letra.\n2_ordenar contando todas las letras.\n");
    printf("3_Ordenar sin diferenciar entre mayusculas y minusculas\n4_SALIR\n");
    scanf("%d",&eleccion);
    switch(eleccion)
    {
        case 1:
        ordenar_nombres1(n);
        imprimir_nombres(n);
        break;
        case 2:
        ordenar_nombres2(n);
        imprimir_nombres(n);
        break;
        case 3:
        ordenar_nombres3(n);
        imprimir_nombres(n);
        break;
        case 4:
        exit(EXIT_SUCCESS);
    }
    return;
}
void carga_nombres(char nom[numero][25])
{
    int x,y;
        for(x=0;x<numero;x++)
        {
        printf("\ningrese el %d nombre:\n",x+1);
        for(y=0;nom[x][y]!='\r'&&y<24;y++)
            {
            nom[x][y]=getche();
            if(nom[x][y]=='\r')
            y--;
            }
        nom[x][y]='\0';
        }
    return;
    }
void ordenar_nombres1(char n[numero][25])
{
    int x,y;
    for(x=0;x<numero;x++)
        for(y=x+1;y<numero;y++)
        if(n[x][0]>n[y][0])
                cambio(n,x,y);
        return;
}
void ordenar_nombres2(char n[numero][25])
{
   int w,x,y,z;
    for(x=0;x<numero;x++)
        for(y=x+1;y<numero;y++)
        {
            for(w=0;n[x][w]!='\0';w++);
            for(z=0;n[y][z]!='\0';z++);
            if(w>z)
            w=z;
    for(z=0;z<w;z++)
    {
        if(z==0&&(n[x][z]>n[y][z]))
                    cambio(n,x,y);
        if(z!=0&&(n[x][z-1]==n[y][z-1])&&(n[x][z]>n[y][z]))
        cambio(n,x,y);
    }
        }
    return;
}
void cambio(char l[numero][25],int a,int b)
{
    int z,aux;
    for(z=0;z<25;z++)
            {
                aux=l[a][z];
                l[a][z]=l[b][z];
                l[b][z]=aux;
            }
            return;
}
void ordenar_nombres3(char n[numero][25])
{
   int w,x,y,z;
    for(x=0;x<numero;x++)
        for(y=x+1;y<numero;y++)
        {
            for(w=0;n[x][w]!='\0';w++);
            for(z=0;n[y][z]!='\0';z++);
            if(w>z)
            w=z;
    for(z=0;z<w;z++)
    {
        if(z==0&&(n[x][z]>n[y][z]+32||n[x][z]>n[y][z]-32))
                    cambio(n,x,y);
        if(z!=0&&(n[x][z]>n[y][z]+32||n[x][z]>n[y][z]-32))
        cambio(n,x,y);
    }
        }
    return;
}
