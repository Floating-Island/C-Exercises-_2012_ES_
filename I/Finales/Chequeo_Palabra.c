#include <stdio.h>
#include <stdlib.h>
int chequeo_palabra(char*);
int main()
{
    int x=0,respuesta;
    char frase[10000];
    printf("ingreese una frase:\n");
    do
    {
       frase[x]=getche();
       if(frase[x]!='\r')
       x++;
    }while(x<1000&&frase[x]!='\r');
    frase[x]='\0';
    respuesta=chequeo_palabra(frase);
        if(respuesta!=0)
        printf("\nsi");

    return 0;
}
int chequeo_palabra(char arreglo[1000])
{
    int x, par=0,impar=0,c_letra_palabra=0;
    for(x=0;arreglo[x]!='\0';x++)
        {
            if(arreglo[x]>='a'&&arreglo[x]<='z'||arreglo[x]>='A'&&arreglo[x]<='Z')
            {
                c_letra_palabra++;
            }
            else
            {
                if(c_letra_palabra%2==0)
                par++;
                else
                impar++;
                c_letra_palabra=0;
            }
        }
        if(par>impar)
        return 1;
        return 0;
}
