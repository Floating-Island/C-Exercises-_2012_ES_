#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double promedio_general(double [][12]);
void medias_mensuales (double [][12]);
double maxima_absoluta(double [][12]);
void cargar_temp (double[][12]);

int main()
{
    double x, max;
    srand(time(NULL));
    double tempmed[31][12];
    cargar_temp(tempmed);
    x=promedio_general(tempmed);
    printf("el promedio general es: %.2lfºC\n",x);
    medias_mensuales(tempmed);
    max=maxima_absoluta(tempmed);
    printf("la maxima absoluta es: %.1lf\n",max);
    return 0;
}
void cargar_temp(double t[31][12])
{
    int x,y,z=0,limites[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    for(x=0;x<12;x++)
    {
        for(y=0;y<limites[z];y++)
            t[y][x]=rand()%46 -5;
        z++;
    }
    printf("\n");
    return;
}
double promedio_general(double prom[31][12])
{
    int x,y,z=0,limites[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    double suma=0;
    for(x=0;x<12;x++)
        {
            for(y=0;y<limites[z];y++)
                suma+=prom[y][x];
                z++;
        }
        return (double)suma/365;
}
void medias_mensuales(double p[31][12])
{
    int x,y,z=0,suma=0,limites[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    for(x=0;x<12;x++)
        {
            for(y=0;y<limites[z];y++)
                suma+=p[y][x];
                z++;
                printf("la maxima mensual de el mes %d es: %.1lf\n",z,(double)suma/limites[z-1]);
                suma=0;
        }
        return;
}
double maxima_absoluta(double m[31][12])
{
     int x,y,z=0,max=0,limites[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    for(x=0;x<12;x++)
        {
            for(y=0;y<limites[z];y++)
                if(max<m[y][x])
                max=m[y][x];
                z++;
        }
        return max;
 }
