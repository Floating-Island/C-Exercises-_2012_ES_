#include <stdio.h>
#include <stdlib.h>
void carga_texto(char*);
void frase(char*);
int main()
{
    char a[1001];
    printf("ingrese una frase:\n");
    carga_texto(a);
    frase(a);
    printf("\n%s",a);
    return 0;
}
void carga_texto(char t[1001])
{
    int y=0;
    do
    {
        t[y]=getche();
        y++;
    }while(y<1000&&t[y-1]!='\r');
    t[y-1]='\0';
    return;
}
void frase(char f[1001])
{
    int a,b=0,c=1;
    double pr=0;
    for(a=0;f[a]!='\0';a++)
    {
        if((f[a]>='a'&&f[a]<='z')&&(b==0))
        f[a]-=32;
        if((f[a]>='a'&&f[a]<='z')||(f[a]>='A'&&f[a]<='Z'))
        {
            b=1;
            pr+=1;
        }
        if((f[a]<'a'||f[a]>'z')&&(f[a]<'A'||f[a]>'Z')&&(b==1))
        {
            c+=1;
            b=0;
        }
    }
    printf("\nla frase tiene %d palabras; el promedio de longitud es %.2lf",c,(double)pr/c);
    return;
}
