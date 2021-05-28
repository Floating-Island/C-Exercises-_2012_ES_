#include <stdio.h>
#include <stdlib.h>

int main()
{
    int segundos,minutos,horas, dias;
    printf("ingrese segundos\n");
    scanf("%d", &segundos);
    minutos=segundos/60;
    horas=segundos/60/60;
    dias=segundos/60/60/24;
    printf("%d dias, %d horas, %d minutos, %d segundos",dias,horas,minutos,segundos);
    return 0;
}
