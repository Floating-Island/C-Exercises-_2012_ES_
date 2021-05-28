#include <stdio.h>
#include <stdlib.h>
void f_entparriba(double*);
int main()
{
    double x;
    scanf("%lf",&x);
    f_entparriba(&x);
    printf("\nRedondeado al mas próximo queda: %lf",x);
    return 0;
}
void f_entparriba(double* e)
{
    if((*e-(int)*e)>0.5)
    *e=(int)*e+1;
    else
    *e=(int)*e;
    return;
}
