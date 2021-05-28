#include <stdio.h>
#include <stdlib.h>
void modif_texto(char*);
int main()
{
    int a=0;
    char texto[1001];
    printf("dale:");
    do
    {
        texto[a]=getche();
        if (texto[a]!='.')
        a++;
    }while(a<1001&&texto[a]!='.');

    modif_texto(texto);
    printf("%s",texto);
    return 0;
}
void modif_texto(char t[1001])
{
    int i;
    for(i=0;t[i]!='.';i++)
    {
        if (t[i]>='A'&&t[i]<='Z')
        t[i]+=32;
        if((t[i]<'a'||t[i]>'z')&&(t[i]<48||t[i]>57))
        t[i]=' ';
    }
    t[i]='\0';
    return;
}
