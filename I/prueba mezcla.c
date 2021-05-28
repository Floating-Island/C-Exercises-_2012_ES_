#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void mezcla_mazo(int*);
int main()
{
    srand(time(NULL));
    int i,y,z,mazo[48]={0};
    mezcla_mazo(mazo);
    return 0;
}
void mezcla_mazo(int mazo[48])
{
    int x,y,contador=0;
    for(x=0;x<48;x++)
       {
        mazo[x]=rand()%12 +1;
        for(y=0;y<48;y++) //El for no puede tener al final un ; porque ejecuta la instrucción vacía.
           if(mazo[x]==mazo[y])
                contador++;
         if(contador>4)
              x--;
        contador=0;
        }
        for(x=0;x<48;x++)
        printf("%d-",mazo[x]);
    return;
}
