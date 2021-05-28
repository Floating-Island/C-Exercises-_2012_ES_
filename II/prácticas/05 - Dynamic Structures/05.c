#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct poli
{
    int exp;
    double coef;
    struct poli* next;
};
typedef struct poli* t_poli;
void cargapoli(t_poli*,int,double);
void imprime(t_poli*);
void derivada(t_poli*);
int main()
{
    t_poli lista=NULL;
    int exponente;
    double coeficiente;
    char preg;
    do
    {
        printf("\ndesea agregar una X? s/n\n");
        if((preg=getche())=='s')
        {
            printf("ingrese el coeficiente: ");
            scanf("%lf",&coeficiente);
            printf("ingrese el exponente: ");
            scanf("%d",&exponente);
            cargapoli(&lista,exponente,coeficiente);
        }
    }while(preg!='n');
    printf("\nAntes de derivar: ");
    imprime(&lista);
    printf("\n derivada: ");
    derivada(&lista);
    imprime(&lista);
    return 0;
}
void cargapoli(t_poli* cadena,int exp,double cof)
{
    t_poli aux;
    if(*cadena==NULL)
    {
        *cadena=malloc(sizeof(t_poli));
        if(*cadena==NULL)
        exit(0);
        (*cadena)->next=NULL;
        (*cadena)->exp=exp;
        (*cadena)->coef=cof;
    }
    else
    {
        for(aux=*cadena;aux->next!=NULL;aux=aux->next);
        aux->next=malloc(sizeof(t_poli));
        if(aux->next==NULL)
            exit(0);
        aux->next->exp=exp;
        aux->next->coef=cof;
        aux->next->next=NULL;
    }
}
void imprime(t_poli* lista)
{
    t_poli aux;
    for(aux=*lista;aux!=NULL;aux=aux->next)
    {
        if(aux->coef>0&&aux->exp!=0)
                printf("+ (%.2lf)X^%d",aux->coef,aux->exp);
        else
        {
            if(aux->exp==0&&aux->coef!=0)
                printf("+ (%.2lf)",aux->coef);
            if(aux->exp<0&&aux->coef!=0)
                printf("+ (%.2lf)(1/X)^%d",aux->coef,aux->exp);
            if(aux->coef==0)
                printf("+0");

        }

    }

}
void derivada(t_poli*lis)
{
    t_poli aux;
    for(aux=*lis;aux!=NULL;aux=aux->next)
        {
            if(aux->exp!=0)
            {
                aux->coef=aux->coef*aux->exp;
                aux->exp--;
            }
            else
                aux->coef=0;
        }
}
