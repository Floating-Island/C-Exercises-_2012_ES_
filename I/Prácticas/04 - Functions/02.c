#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int validacion (void);
double raiz (double, int);

int validacion(void)
{
    int exponente;
    printf("ingrese un exponente");
    scanf("%d",&exponente);
    while (exponente <=0)
    {
        printf("\n error, el exponente debe ser positivo");
        scanf("%d",&exponente);
    }
    return exponente;
}

double raiz(double b, int e)
{
    double r;
    r= pow(b,(1.0/e));
    return r;
}
int main ()
{
    int r;
    double numero;
    printf("ingrese un numero real");
    scanf("%lf",&numero);
    r=validacion ();
    printf("la raiz %d de %.3f es %.3lf",r,numero,raiz(numero,r));
    return 0;
}
