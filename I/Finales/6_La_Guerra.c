//6) la Guerra.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void mezcla_mazo(int*);
int repartir(int,int,int*);
int puntaje(int,int,int);
int hay_empate(int,int);
void ganador(int,int);





int main()
{
    srand(time(NULL));
    int mazo[48]={0},num,mano=1,repartecarta=0,carta1,carta2,empatan=0,punto_jug1=0,punto_jug2=0;
    mezcla_mazo(mazo);
    printf("empieza el juego:\n");
    do
    {
        num=1;
        carta1=repartir(num,repartecarta,mazo);
        repartecarta++;
        num=2;
        carta2=repartir(num,repartecarta,mazo);
        repartecarta++;
        punto_jug1+=puntaje(carta1,carta2,empatan);
        punto_jug2+=puntaje(carta2,carta1,empatan);
        if(empatan==1)
        empatan=0;
        empatan=hay_empate(carta1,carta2);
       mano++;
    }while(mano<24);
    ganador(punto_jug1,punto_jug2);
    return 0;
}
void mezcla_mazo(int deck[48])
{
    int x,y,contador=0;
    for(x=0;x<48;x++)
    {
        deck[x]=rand()%12 +1;
        for(y=0;y<48;y++)
        if(deck[x]==deck[y])
            contador++;
            if(contador>4)
                x--;
                contador=0;
    }
    return;
}
int repartir(int num_jugador,int posicion,int mazo[48])
{
    int carta;
    printf("\njuega el jugador %d:",num_jugador);
    carta=mazo[posicion];
    printf("\nrecibe: %d",carta);
    return carta;
}
int puntaje(int carta1,int carta2,int empate)
{
    int p=0;
    if(carta1>carta2)
    {
        p++;
        if(empate==1)
        p++;
    }
    return p;
}
int hay_empate(int carta1,int carta2)
{
    if(carta1==carta2)
    return 1;
    return 0;
}
void ganador(int puntaje_jug1,int puntaje_jug2)
{
    printf("\nlos resultados son:\n Para el jugador 1: %d\nPara el jugador 2: %d",puntaje_jug1,puntaje_jug2);

    if(puntaje_jug1>puntaje_jug2)
    printf("\nGano el jugador: 1!!!!!!");
    if(puntaje_jug2>puntaje_jug1)
    printf("\nGano el jugador: 2!!!!!!");
    if(puntaje_jug1==puntaje_jug2)
    printf("\nHubo empate!!!");
return;
}
