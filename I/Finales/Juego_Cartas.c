#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mezcla_mazo(int*);
int repartidor_cartas(int,int*,int*);
void mostrar_cartas(int*);
void cantidad_cartas(int*,int);
int mostrar_cantidad(int,int*);
void ganador(int);
int quita_cartas(int,int*);
int saca_cartas(int,int*);
int jugador(int,int*,int);

int main()
{
    srand(time(NULL));
    int x=0,y,num,mazo[48]={0},jug1[12],jug2[12],jug3[12],jug4[12],carta=0;
    mezcla_mazo(mazo);
    for(y=0;y<48;y++)
    printf("%d-",mazo[y]);
    x=repartidor_cartas(x,mazo,jug1);
    x=repartidor_cartas(x,mazo,jug2);
    x=repartidor_cartas(x,mazo,jug3);
    x=repartidor_cartas(x,mazo,jug4);
    do
    {
        num=1;
        carta=jugador(num,jug1,carta);
        num=2;
        carta=jugador(num,jug2,carta);
        num=3;
        carta=jugador(num,jug3,carta);
        num=4;
        carta=jugador(num,jug4,carta);
    }while(num!=5);
    return 0;
}
void mezcla_mazo(int mazo[48])
{
    int x,y,contador=0;
    for(x=0;x<48;x++)
       {
        mazo[x]=rand()%12 +1;
        for(y=0;y<48;y++)
           if(mazo[x]==mazo[y])
                contador++;
         if(contador>4)
              x--;
        contador=0;
        }
    return;
}
int repartidor_cartas(int x,int m[48],int p[12])
{
    int y=12;
    for(y+=x;x<y;x++)
    p[y-1-x]=m[x];
    return x;
}
void mostrar_cartas(int j[12])
{
    int y=1;
    mostrar_cantidad(y,j);
    printf("\n");
    return;
}
void cantidad_cartas(int a[12],int jugador)
{
    int c=0;
    c=mostrar_cantidad(c,a);
    if (c==0)
    ganador(jugador);
    printf("le quedan %d cartas",c);
    return;
}
int mostrar_cantidad(int y,int j[12])
{
    int x,c=0;
    for(x=0;x<12;x++)
    if(j[x]!=0)
    switch(y)
    {
        case 1: printf("%d-",j[x]);
        break;
        default: c+=1;
        break;
    }
    return c;
}
void ganador(int x)
{
    printf("Al jugador %d no le quedan cartas.\nEl jugador %d GANOOOO!!!!!!",x,x);
    exit(0);
}
int saca_cartas(int x,int j[12])
{
    if(x>=2&&x<=4)
    x=2;
    if(x>=9&&x<=11)
    x=3;
    if(x>=5&&x<=8)
    x=4;
    if(x==12)
    return 0;
    x=quita_cartas(x,j);
    return x;
}
int quita_cartas(int a,int c[12])
{
    int x,b=0;
    for(x=0;x<12;x++)
        if(c[x]!=0)
            switch (a)
            {
                case 2: 
                    if(c[x]%2==0)
                        b=hacer(c,x);
                    break;

                case 3: 
                    if(c[x]%2!=0)
                        b=hacer(c,x);
                    break;

                case 4: 
                    if(c[x]<5||c[x]>8)
                        b=hacer(c,x);
                    break;

                case 5:
                    break;

                default:
                    b=hacer(c,x);
                    break;
            }
    return b;
}

int hacer(int c[12],int x)
{
    int b;
    b=c[x];
    c[x]=0;
    return b;
}

/*
int quita_cartas(int a,int c[12])
{
    int x,b=0;
    for(x=0;x<12;x++)
    if(c[x]!=0)
    switch (a)
    {
        case 2: 
        if(c[x]%2==0)
            goto hacer;
        break;
        
        case 3: 
        if (c[x]%2!=0)
            goto hacer;
        break;
        
        case 4: 
        if (c[x]<5||c[x]>8)
            goto hacer;
        break;

        case 5:
        return b;
        break;
        
        default: 
            goto hacer;
        break;
    }
    hacer:
    b=c[x];
    c[x]=0;
    return b;
}
*/



int jugador(int numero,int mano[12],int anterior)
{
    int carta=0;
    printf("\njuega el jugador %d:\n-tiene estas cartas:\n",numero);
    mostrar_cartas(mano);
    carta=saca_cartas(anterior,mano);
    if(carta!=0)
    printf("tiro la carta: %d\n",carta);
    else
    printf("no puede tirar ninguna\n");
    cantidad_cartas(mano,numero);
    while(carta==1)
    {
        anterior=1;
        carta=saca_cartas(anterior,mano);
        if(carta!=0)
    printf("\ntiro la carta: %d\n",carta);
        cantidad_cartas(mano,numero);
    }
    return carta;
}
