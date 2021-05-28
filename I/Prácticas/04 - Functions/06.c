#include <stdio.h>
#include <stdlib.h>

int ingresar_texto(void);
int es_letra (unsigned char);
int main()
{
    int len;
    printf("ingrese texto (punto para finalizar):");
    len=ingresar_texto();
    printf("\nEl texto tiene %d letras.",len);
    return 0;
}
int es_letra(unsigned char a)
{
   int p=1;
       if ((a>='a'&&a<='z')||(a>='A'&&a<='Z'))
        return p;
        else
        return 0;
}
int ingresar_texto(void)
{
    char b[1000];
    int r,l=0;
   for(r=0;b[r]!='.';r++)
    {
        b[r]=getche();
        l+=es_letra(b[r]);
        if(b[r]=='.')
        r--;
    }
    return l;
}

