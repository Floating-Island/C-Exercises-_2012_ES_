//8) Con baraja francesa.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void mezcla_mazo(int*);
int repartir(int*,int,int*);
void ordenar(int*);
int hay_escalera(int*);
void punto_escalera(int*,int*);
void puntero_figura(int*,int*);
void puntos(int*,int*,int*,int*,int*,int*);
void ganador(int*);
void puntaje_parcial(int*);
void reparticion(int*,int*,int*,int*,int*,int*);
void muestra_cartas(int*,int*,int*,int*,int*);
void mostrar_cartas(int*);
void ordenatodo(int*,int*,int*,int*,int*);




int main()
{
    int puntuacion[5]={0},x,pos=0,mazo[52],juga1[5],juga2[5],juga3[5],juga4[5],juga5[5];
    while(pos<50)
    {
        mezcla_mazo(mazo);
        reparticion(mazo,juga1,juga2,juga3,juga4,juga5);
        ordenatodo(juga1,juga2,juga3,juga4,juga5);
        muestra_cartas(juga1,juga2,juga3,juga4,juga5);
        puntos(puntuacion,juga1,juga2,juga3,juga4,juga5);
        ganador(puntuacion);
        puntaje_parcial(puntuacion);
        for(x=0;x<52;x++)
        mazo[x]=0;
    }
    return 0;
}
void ordenatodo(int juga1[5],int juga2[5],int juga3[5],int juga4[5],int juga5[5])
{
    ordenar(juga1);
    ordenar(juga2);
    ordenar(juga3);
    ordenar(juga4);
    ordenar(juga5);
    return;
}
void muestra_cartas(int jugador1[5],int jugador2[5],int jugador3[5],int jugador4[5],int jugador5[5])
{
    printf("\nEl jugador 1 tiene:\n");
    mostrar_cartas(jugador1);
    printf("\nEl jugador 2 tiene:\n");
    mostrar_cartas(jugador2);
    printf("\nEl jugador 3 tiene:\n");
    mostrar_cartas(jugador3);
    printf("\nEl jugador 4 tiene:\n");
    mostrar_cartas(jugador4);
    printf("\nEl jugador 5 tiene:\n");
    mostrar_cartas(jugador5);
    printf("\n");
    return;
}
void mostrar_cartas(int jugador[5])
{
    int x;
    for(x=0;x<5;x++)
    {
        if(jugador[x]>1&&jugador[x]<11)
        printf("-%d",jugador[x]);
        if(jugador[x]==1)
        printf("-A");
        if(jugador[x]==11)
        printf("-j");
        if(jugador[x]==12)
        printf("-Q");
        if(jugador[x]==13)
        printf("-K");
    }
return;
}

void reparticion(int mazo[52],int jug1[5],int jug2[5],int jug3[5],int jug4[5],int jug5[5])
{
    int pos=0;
    pos=repartir(jug1,pos,mazo);
    pos=repartir(jug2,pos,mazo);
    pos=repartir(jug3,pos,mazo);
    pos=repartir(jug4,pos,mazo);
    pos=repartir(jug5,pos,mazo);
    return;
}
void mezcla_mazo(int deck[52])
{
    int x,y,contador=0;
    for(x=0;x<52;x++)
    {
        deck[x]=rand()%13 +1;
        for(y=0;y<52;y++)
        if(deck[x]==deck[y])
        contador++;
        if(contador>4)
        x--;
        contador=0;
    }
    return;
}
int repartir(int jugador[5],int posicion,int mazo[52])
{
    int x,y=posicion+5;
    for(x=0;posicion<y;posicion++)
    {
        jugador[x]=mazo[posicion];
        x++;
    }
   return posicion;
}
int hay_escalera(int jugador[5])
{
    int y,z,contador=1;
    for(y=0;y<5;y++)
    if(((jugador[y+1])<11)&&(jugador[y]==jugador[y+1]-1))
        contador++;
    if(contador==5)
    return jugador[4];
    return 0;
}
void ordenar(int mano[5])
{
    int x,y,aux;
    for(x=0;x<5;x++)
        for(y=0;y<5;y++)
        if(mano[x]<mano[y])
        {
            aux=mano[x];
            mano[x]=mano[y];
            mano[y]=aux;
        }
    return;
}
void puntos(int puntaje_total[5],int jug1[5],int jug2[5],int jug3[5],int jug4[5],int jug5[5])
{
    int carta_escalera[5],figuras[5],x,contador=0;
    carta_escalera[0]=hay_escalera(jug1);
    carta_escalera[1]=hay_escalera(jug2);
    carta_escalera[2]=hay_escalera(jug3);
    carta_escalera[3]=hay_escalera(jug4);
    carta_escalera[4]=hay_escalera(jug5);
    for(x=0;x<5;x++)
    if(carta_escalera[x]!=0)
        contador++;
    if (contador>0)
    {
        punto_escalera(puntaje_total,carta_escalera);
    }
    if(contador==0)
    {
        printf("\nno hay escaleras:\n");
        figuras[0]=jug1[4];
        figuras[1]=jug2[4];
        figuras[2]=jug3[4];
        figuras[3]=jug4[4];
        figuras[4]=jug5[4];
        puntero_figura(puntaje_total,figuras);
    }
    return;
}
void punto_escalera(int puntotal[5],int carta_escalera[5])
{
    int max=0,x,contador=0;
    for(x=0;x<5;x++)
    if(carta_escalera[x]>max)
    max=carta_escalera[x];
    for(x=0;x<5;x++)
    if(max==carta_escalera[x])
        {
            contador++;
            puntotal[x]+=1;
            printf("\nel jugador %d tiene la escalera mas alta",x+1);
        }
    if (contador>1)
    printf("\nHay empate, todos los empatados se llevan 1 punto");
    else
        for(x=0;x<5;x++)
    if(max==carta_escalera[x])
        {
            puntotal[x]+=4;
            printf("\El jugador %d se lleva 5 puntos",x+1);
        }
    return;
}
void puntero_figura(int puntaje[5],int carta_alta[5])
{
    int x,max=0,contador=0;
    for(x=0;x<5;x++)
    if((carta_alta[x]>10)&&(carta_alta[x]>max))
    max=carta_alta[x];
    for(x=0;x<5;x++)
    if(max==carta_alta[x])
        {
            contador++;
            puntaje[x]+=1;
            printf("\nel jugador %d tiene la figura mas alta",x+1);
        }
    if (contador>1)
    printf("\nHay empate, todos los empatados se llevan 1 punto");
    if(max==0)
    printf("\nno hay figuras, ninguno se lleva puntos");
    return;
}
void ganador(int puntaje[5])
{
    int x,contador=0;
    for(x=0;x<5;x++)
    if(puntaje[x]==50)
    {
       printf("\nel Jugador %d llego a los 50 puntos",x+1);
       contador++;
    }
    if(contador>1)
    {
    printf("\nHubo EMPATE!! todos los jugadores empatados GANAN!!!");
    puntaje_parcial(puntaje);
    exit(0);
    }
    if (contador==1)
    {
        printf(". Entonces GANOOO!!!!!");
        puntaje_parcial(puntaje);
        exit(0);
    }
    return;
}
void puntaje_parcial(int puntaje[5])
{
    int x;
    printf("\n RESULTADOS:");
    for(x=0;x<5;x++)
    printf("\nJugador %d: %d",x+1,puntaje[x]);
    return;
}
