//7) Craps.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int dado();
int dados(int,int);
void gana_pierde(int);
void revancha(int);


int main()
{
    srand(time(NULL));
    int dado1,dado2,x=0;
    do
    {
        dado1=dado();
        dado2=dado();
        gana_pierde(dados(dado1,dado2));
        x++;
    }while(x<5);

    return 0;
}
int dado()
{
    int c;
    c=rand()%6 +1;

    return c;
}
int dados(int dado1,int dado2)
{
    printf("\nsalio el %d y el %d",dado1,dado2);
    printf("\n Su suma es: %d",dado1+dado2);
    return dado1+dado2;
}
void gana_pierde(int res_dados)
{
    if(res_dados==2||res_dados==3||res_dados==12)
    printf("\npierde");
    if(res_dados==7||res_dados==11)
    printf("\nGANA");
    if(res_dados!=2&&res_dados!=3&&res_dados!=12&&res_dados!=7&&res_dados!=11)
        {
            printf("\nDebe tirar de vuelta:");
            revancha(res_dados);
        }
        return;
}
void revancha(int resultado_anterior)
{
    int c,d;
        while(c!=resultado_anterior&&c!=7)
    {
        c=dado();
        d=dado();
        if(c+d==resultado_anterior)
        {
        c=dados(c,d);
          printf("\nGANA");
        }
        if(c+d==7)
        {
        c=dados(c,d);
        printf("\npierde");
        }
    }
    return;
}
