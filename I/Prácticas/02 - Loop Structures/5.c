#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contador1=0,contador2=0;
    char b;
    printf("\ningrese un texto que finalice con un asterisco\n");
    do
    {
        b=getche();
        if (b>='A'&&b<='Z')
        {
            contador1++;
        }
        if(b>='a'&&b<='z')
        {
            contador2++;
        }
    }while(b!='*');
    printf("\nEn el texto hay %d mayusculas y %d minusculas",contador1,contador2);
    return 0;
}
