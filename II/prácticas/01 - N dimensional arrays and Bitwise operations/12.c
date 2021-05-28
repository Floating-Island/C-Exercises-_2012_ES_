#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
char f_cambio_mayus_minus(char);
int main()
{
    char a;
    printf("ingrese una letrilla\n");
    a=getche(),
    printf("\n se transforma en: %c",a=f_cambio_mayus_minus(a));
    return 0;
}
char f_cambio_mayus_minus(char x)
{
    return (x&32)? x-32:x+32;
}
