#include <stdio.h>
#include <stdlib.h>

struct s_persona
{
    char nombre[25];
    int edad;
    int fnacimiento;
};
struct s_nodo
{
    struct s_persona prs;
    struct s_nodo * sig;
};
typedef struct s_nodo * t_nodo;
void agregar(t_nodo*,char*,int,int);
void imprimir(t_nodo);
int main()
{
    t_nodo lista=NULL;
    t_nodo p=NULL;
    t_nodo p1=NULL;

    agregar(&lista,"chapo",18,111094);
    agregar(&lista,"Pancho",18,12594);
    agregar(&lista,"Miltoooon",19,200792);
    agregar(&lista,"Maria",22,80890);
    printf("La lista entera es:\n");
    imprimir(lista);
    printf("\nLa primer pila(mayores de 21) es :\n"); //por aca iria la parte de carga, creo
    imprimir(p);
    printf("\nLa segunda pila(menores o con 21) es:\n");
    imprimir(p1);

    return 0;
}

void agregar(t_nodo*  lista,char* n,int ed,int fn)
{
        if(*lista!=NULL)
        {
            agregar(&(*lista)->sig,n,ed,fn);
        }else
        {
            *lista=malloc(sizeof(struct s_nodo));
            if(*lista!=NULL)
            {
                ((*lista)->prs.nombre[25])=*n; //aca pasa todo el quilombo del nombre
                ((*lista)->prs.edad)=ed;
                ((*lista)->prs.fnacimiento)=fn;
                (*lista)->sig=NULL;
            }else
            {
               exit(0);
            }
        }
}
 void cargar(t_nodo *lista,t_nodo p,t_nodo p1)
 {
     if(((*lista)-> prs.edad)>21)
     {
          p=malloc(sizeof(struct s_nodo));
         if(p!=NULL)
         {
             p->prs=(*lista)->prs;
         }else
         {
             p1->prs=(*lista)->prs;
         }
     }else
     {
         return;
     }
 }
void imprimir(t_nodo l)
{
    if(l->sig!=NULL)
    {
        printf("edad: %d \n",l->prs.edad);
        printf("f. nacimiento: %d\n ",l->prs.fnacimiento);
        printf("nombre: %s\n ",l->prs.nombre);
        imprimir((l)->sig);
    }
    else
        {
        printf("edad: %d\n ",l->prs.edad);
        printf("f. nacimiento: %d\n ",l->prs.fnacimiento);
        printf("nombre: %s\n ",l->prs.nombre);
        }
}

