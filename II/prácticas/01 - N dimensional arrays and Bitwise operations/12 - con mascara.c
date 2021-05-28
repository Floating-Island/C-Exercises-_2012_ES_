#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
char f_cambio_mayus_minus(char);
char f_cambio_sin_XOR (char);
int main()

{
    char a;
    printf("ingrese una letrilla\n");
    a=getche(),
    printf("\n se transforma en: %c",a=f_cambio_mayus_minus(a));
    printf("\n se transforma en: %c",a=f_cambio_sin_XOR(a));
    return 0;
}
char f_cambio_mayus_minus(char x)
{
    return x^32;
}
char f_cambio_sin_XOR (char a)
{
    return a&~(a&(char)1<<32);
}
