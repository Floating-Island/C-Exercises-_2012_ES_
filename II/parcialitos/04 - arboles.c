#include <stdio.h>
#include <stdlib.h>
typedef struct s_arbol
{
    int dato;
    struct s_arbol *izq,*der;
}*t_arbol;
void cargar(t_arbol*,int);
void inorder(t_arbol);
void preorder(t_arbol);
void posorder(t_arbol);
int main()
{
    t_arbol raiz=NULL;
    int entero;
    printf("ingrese numeros enteros:\n");
    do
    {
        scanf("%d",&entero);
        if(entero%2!=0)
            cargar(&raiz,entero);
    }while(entero!=0);
    printf("\nlos impares en inorder son : ");
    inorder(raiz);
    printf("\nlos impares en preorder son: ");
    preorder(raiz);
    printf("\nlos impares en posorder son: ");
    posorder(raiz);
    printf("\nlos impares por niveles son: ");
    posorder(raiz);
    return 0;
}
void cargar(t_arbol *r,int val)
{
    if(*r!=NULL)
    {
        if(val<=(*r)->dato)
            cargar(&((*r)->izq),val);
        if (val>(*r)->dato)
            cargar(&((*r)->der),val);
    }
    else
    {
        *r=(struct s_arbol*)malloc(sizeof(struct s_arbol));
        if(*r==NULL)
            exit(0);
        (*r)->dato=val;
        (*r)->izq=NULL;
        (*r)->der=NULL;
    }
}
void inorder(t_arbol a)
{
    if(a!=NULL)
    {
        inorder(a->izq);
        printf("%d ",a->dato);
        inorder(a->der);
    }
}
void preorder(t_arbol ar)
{
    if(ar!=NULL)
    {
        printf("%d ",ar->dato);
        preorder(ar->izq);
        preorder(ar->der);
    }
}
void posorder(t_arbol arb)
{
    if(arb!=NULL)
    {
        posorder(arb->izq);
        posorder(arb->der);
        printf("%d ",arb->dato);
    }
}
