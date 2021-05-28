#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
char c[100];
printf("ingrese un texto\n");
for (i=0;i<99;i++)
    c[i]=getche ();
while ((c[i]<'A'||c[i]>'Z')&&(c[i]<'a'||c[i]>'z'))
i--;
c[i+1]='\0';

i=0;
while ((c[i]<'A'||c[i]>'Z')&&(c[i]<'a'||c[i]>'z'))
    i++;
for (j=0;c[i]!='\0';j++)
{
    c[j]=c[i];
    i++;
}
c[j]='\0';
printf("\n%s",c);



    return 0;
}
