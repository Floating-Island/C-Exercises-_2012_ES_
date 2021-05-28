#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo
{
    int dato;
    struct s_nodo *izq,*der;
}*t_nodo;

typedef struct s_nivel
{
    int nivel;
    struct s_nodo nodo;
}*t_nivel;

void cargar(t_nodo*,int);
void inorder(t_nodo);
void preorder(t_nodo);
void posorder(t_nodo);
void por_niveles(t_nodo);
void grafica_arbol(t_nodo);
int main()
{
    t_nodo raiz=NULL;
    int entero;

    printf("ingrese numeros enteros:\n");
    do
    {
        scanf("%d",&entero);
            cargar(&raiz,entero);
    }while(entero!=0);
    printf("\nlos numeros en inorder son : ");
    inorder(raiz);
    printf("\nlos numeros en preorder son: ");
    preorder(raiz);
    printf("\nlos numeros en posorder son: ");
    posorder(raiz);
    printf("\nlos niveles del arbol graficado son:\n");
    grafica_arbol(raiz);
    printf("\nlos numeros por niveles son: ");
    por_niveles(raiz);
    return 0;
}
void cargar(t_nodo *r,int val)
{
    if(*r!=NULL)
    {
        if(val<=(*r)->dato)
            cargar(&(*r)->izq,val);
        if (val>(*r)->dato)
            cargar(&(*r)->der,val);
    }
    else
    {
        *r=malloc(sizeof(struct s_nodo));
        if(*r==NULL)
            exit(0);
        (*r)->dato=val;
        (*r)->izq=NULL;
        (*r)->der=NULL;
    }
}
void inorder(t_nodo a)
{
    if(a!=NULL)
    {
        inorder(a->izq);
        printf("%d ",a->dato);
        inorder(a->der);
    }
}
void preorder(t_nodo ar)
{
    if(ar!=NULL)
    {
        printf("%d ",ar->dato);
        preorder(ar->izq);
        preorder(ar->der);
    }
}
void posorder(t_nodo arb)
{
    if(arb!=NULL)
    {
        posorder(arb->izq);
        posorder(arb->der);
        printf("%d ",arb->dato);
    }
}
void por_niveles(t_nodo raiz)
{
    int posoriginal=0,posagregada=0;
    t_nodo aux=NULL;
    aux=malloc(sizeof(struct s_nodo));
    if(aux==NULL)
        exit(0);
    if(raiz!=NULL)
    {
        aux=raiz;
    while(posoriginal<posagregada+1)
    {
        if((aux+posoriginal)->izq!=NULL)
        {
            aux=realloc(aux,sizeof(struct s_nodo)*(++posagregada+1));
            *(aux+posagregada)=*(aux+posoriginal)->izq;
        }
        if((aux+posoriginal)->der!=NULL)
        {
            aux=realloc(aux,sizeof(struct s_nodo)*(++posagregada+1));
            *(aux+posagregada)=*(aux+posoriginal)->der;
        }
        posoriginal++;
    }
    for(posoriginal=0;posoriginal<(posagregada+1);posoriginal++)
        printf("%d ",(aux+posoriginal)->dato);
    }
}
void grafica_arbol(t_nodo raiz)
{
    int posoriginal=0,posagregada=0;
    t_nivel aux=NULL;
    aux=malloc(sizeof(struct s_nivel));
    if(aux==NULL)
        exit(0);
    if(raiz!=NULL)
    {
        aux->nodo=*raiz;
        aux->nivel=1;
    while(posoriginal<posagregada+1)
    {
        if((aux+posoriginal)->nodo.izq!=NULL)
        {
            aux=realloc(aux,sizeof(struct s_nivel)*(++posagregada+1));
            (aux+posagregada)->nodo=*(aux+posoriginal)->nodo.izq;
            (aux+posagregada)->nivel=(aux+posoriginal)->nivel+1;
        }
        if((aux+posoriginal)->nodo.der!=NULL)
        {
            aux=realloc(aux,sizeof(struct s_nivel)*(++posagregada+1));
            (aux+posagregada)->nodo=*(aux+posoriginal)->nodo.der;
            (aux+posagregada)->nivel=(aux+posoriginal)->nivel+1;
        }
        posoriginal++;
    }
    posoriginal=0;
    do
    {
        if(posoriginal!=0&&(aux+posoriginal)->nivel!=(aux+posoriginal-1)->nivel)
            printf("\n");
        printf("%d ",(aux+posoriginal)->nodo.dato);
        posoriginal++;
    }while(posoriginal<posagregada+1);
    }
}
