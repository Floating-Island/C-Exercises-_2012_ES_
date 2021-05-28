#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cont=0,aplazados=0,aprobados=0,promocionados=0;
    double a,notastotal=0;
    printf("ingrese nota:");
    scanf("%lf",&a);
    while(a!=0)
        {
           while ((a>=1&&a<=10))
           {
               if(a<4)
               {
                   aplazados++;
               }
               if ((a>=4)&&(a<=7))
               {
                   aprobados++;
               }
               if(a>7)
               {
                   promocionados++;
               }
               notastotal=notastotal+a;
               cont++;
               a=0;
           }
           printf("ingrese nota:");
                scanf("%lf",&a);
        }
        printf("Cantidad de aplazados:%d (%.0lf%%)\n",aplazados,100*(double)aplazados/(double)cont);
        printf("Cantidad de aprobados:%d (%.0lf%%)\n",aprobados,100*(double)aprobados/(double)cont);
        printf("Cantidad de promocionados:%d (%.0lf%%)\n",promocionados,100*(double)promocionados/(double)cont);
        printf("Promedio general:%.0lf",(double)notastotal/(double)cont);
    return 0;
}
