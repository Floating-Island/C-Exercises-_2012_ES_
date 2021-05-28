#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0;
    char c[100],l,lc;
    printf("ingrese un texto\n");
    while ((i<99)&&(c[i]!='\r'))
    {
       c[i]=getche ();
       if (c[i]!='\r')
       i++;
    }
    c[i+1]='\0';
    printf("\nelija una letra a cambiar: ");
    l=getche ();
    printf("\ningrese la letra por la que desee cambiarla: ");
    lc= getche ();
    for (i=0;c[i]!='\o';i++)
    {
        if (c[i]==l)
        c[i]=lc;
    }
    printf("\nel texto resultante es: \n %s",c);
    return 0;
}
