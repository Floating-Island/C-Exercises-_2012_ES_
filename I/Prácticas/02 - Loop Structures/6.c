#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contador1=0,contador2=0;
    char b;

    printf("ingrese un texto que finalice con un asterisco\n");
    do
    {
        b=getche();
        if ((b=='a')||(b=='A')||(b=='e')||(b=='E')||(b=='i')||(b=='I')||(b=='o')||(b=='O')||(b=='u')||(b=='U'))
        {
            contador1++;
        }
        if ((b!='\r')&&(b!=32)&&(!((b=='a')&&(b=='A')&&(b=='e')&&(b=='E')&&(b=='i')&&(b=='I')&&(b=='o')&&(b=='O')&&(b=='u')&&(b=='U'))))
        {
            contador2++;
        }
    }while(b!='\r');
    contador2=contador2-contador1;
    printf("\nHay %d vocales y %d consonantes",contador1,contador2);
    return 0;
}
