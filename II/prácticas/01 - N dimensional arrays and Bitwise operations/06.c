#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 5
struct alu;
struct com;
struct mat;
struct carrera;
void f_cargadatos(struct carrera);
void f_cargamasiva(struct carrera);
void f_cargaselectiva(struct carrera);
void f_cargarapida(struct carrera);
void f_inicializador (struct carrera);
int f_opcion(struct carrera);
void f_prommat(struct carrera);
void f_promcom(struct carrera);
void f_promalu(struct carrera);
void f_prompar(struct carrera);
void f_prom(struct carrera,int,int,int,int);
struct alu
{
    int nota[2];
};
struct com
{
    struct alu alumnos[max];
};
struct mat
{
    struct com comisiones[max];
};
struct carrera
{
    struct mat materia[max];
};
int main()
{
    srand(time(NULL));
    int op=0;
    struct carrera ingenieria;
    do
    {
    f_inicializador(ingenieria);
    f_cargadatos(ingenieria);
    op=f_opcion(ingenieria);
    }while(op!=0);
    return 0;
}
void f_inicializador(struct carrera ingeni)
{
    int materia,comision,alumno,parcial;
        for(materia=0;materia<max;materia++)
    for(comision=0;comision<max;comision++)
    for(alumno=0;alumno<max;alumno++)
    for(parcial=0;parcial<2;parcial++)
    ingeni.materia[materia].comisiones[comision].alumnos[alumno].nota[parcial]=1;
}
void f_cargadatos(struct carrera ing)
{
    int opcion=1;
    printf("¿Que tipo de carga desea hacer?\n1_Masiva\n2_Selectiva\n3_FastCharge\n");
    scanf("%d",&opcion);
    switch(opcion)
    {
        case 1:
        f_cargamasiva(ing);
        break;
        case 2:
        f_cargaselectiva(ing);
        break;
        case 3:
        f_cargarapida(ing);
        break;
    }
    return;
}
void f_cargamasiva (struct carrera inge)
{
       int materia,comision,alumno,parcial;
    for(materia=0;materia<max;materia++)
    for(comision=0;comision<max;comision++)
    for(alumno=0;alumno<max;alumno++)
    for(parcial=0;parcial<2;parcial++)
    {
        printf("ingrese la nota de la materia %d-comision %d-alumno %d- parcial %d:",materia+1,comision+1,alumno+1,parcial+1);
        scanf("%d",&inge.materia[materia].comisiones[comision].alumnos[alumno].nota[parcial]);
    }
}
void f_cargaselectiva (struct carrera ing)
{
        int materia,comision,alumno,parcial,finalizar=0;
        while(finalizar!=-1)
        {
            printf("\ningrese la materia:");
            scanf("%d",&materia);
            printf("\ningrese la comision:");
            scanf("%d",&comision);
            printf("\ningrese el numero de alumno:");
            scanf("%d",&alumno);
            if(materia<=max&&comision<=max&&alumno<=max&&materia>0&&comision>0&&alumno>0)
            {
            printf("\ningrese el numero de parcial:");
            scanf("%d",&parcial);
            if (parcial>0&&parcial<3)
            {
            printf("\ningrese la nota:");
            scanf("%d",&ing.materia[materia-1].comisiones[comision-1].alumnos[alumno-1].nota[parcial-1]);
            printf("\n ingrese -1 si quiere finalizar:");
            scanf("%d",&finalizar);
            }
            else
            printf("\nERROR, ingrese nuevamente los datos\n");
            }
            else
            printf("\nERROR, ingrese nuevamente los datos\n");
        }
        return;
}
void f_cargarapida(struct carrera ing)
{
    int materia,comision,alumno,parcial;
    for(materia=0;materia<max;materia++)
    for(comision=0;comision<max;comision++)
    for(alumno=0;alumno<max;alumno++)
    for(parcial=0;parcial<2;parcial++)
    {
        ing.materia[materia].comisiones[comision].alumnos[alumno].nota[parcial]=rand()%10+1;
        printf("%d-",ing.materia[materia].comisiones[comision].alumnos[alumno].nota[parcial]);
    }
    return;
}
void f_prom(struct carrera ing,int m,int c,int a,int p)
{
    double pr=0;
    for(;m<max;m++)
    for(;c<max;c++)
    for(;a<max;a++)
    for(;pr<2;pr++)
    pr+=ing.materia[m].comisiones[c].alumnos[a].nota[p];
    printf("el promedio es %.2lf",pr/(double)(max*max*max*2));
}
void f_prommat(struct carrera ing)
{
    int m;
    do
    {
    printf("\ningrese el numero de materia:");
    scanf("%d",&m);
    }while(m<1||m>5);
    f_prom(ing,m-1,0,0,0);
    return;
}
void f_promalu (struct carrera ing)
{
    int c,a;
    do
    {
        printf("\ningrese el numero de la comision:");
    scanf("%d",&c);
        printf("\ningrese el numero de alumno:");
    scanf("%d",&a);
    }while(c<1||c>max||a<1||a>max);
    f_prom(ing,0,c-1,a-1,0);
    return;
}
void f_promcom(struct carrera ing)
{
    int c;
    do
    {
        printf("ingrese la comsion\n");
        scanf("%d",&c);
    }while(c<1||c>max);
    f_prom(ing,0,c,0,0);
    return;
}
void f_prompar(struct carrera ing)
{
    int m,c,p;
        do
    {
        printf("\ningrese el numero de la comision:");
    scanf("%d",&c);
        printf("\ningrese el numero de materia:");
    scanf("%d",&m);
            printf("\ningrese el numero de parcial:");
    scanf("%d",&p);
    }while(c<1||c>max||m<1||m>max||p<1||p>2);
    f_prom(ing,m,c,0,p);
    return;
}
int f_opcion(struct carrera ing)
{
    int seleccion;
    printf("\nelija una opcion:\n1-Ver Promedio de una materia.\n2-Ver promedio de un alumno.\n3-Ver promedio de una Comision.\n4-Ver promedio de un parcial.\n5-Volver a cargar los datos.\n6-Salir.");
    scanf("%d",&seleccion);
    switch (seleccion)
    {
        case 1:
        f_prommat(ing);
        break;
        case 2:
        f_promalu(ing);
        break;
        case 3:
        f_promcom(ing);
        break;
        case 4:
        f_prompar(ing);
        break;
        case 5:
        return 1;
        break;
        case 6:
        exit(0);
        break;
    }
    return 0;
}
