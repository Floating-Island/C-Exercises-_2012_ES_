#include <stdio.h>
#include <stdlib.h>
void carga_texto(char*);
int bool_palabra(char*,char*);
int frase_palabra(char*,char*);
int frases(char*,char*);
int main()
{
    int a,b,c;
    char x[1001],y[1001],z[1001];
    printf("ingrese la primer frase,finalice con enter:\n");
    carga_texto(x);
    printf("\ningrese la segunda frase,finalice con enter:\n");
    carga_texto(y);
    printf("\ningrese la palabra a buscar,finalice con enter:\n");
    carga_texto(z);
    a=frase_palabra(z,x);
    b=frase_palabra(z,y);
    c=frases(x,y);
    printf("\nen la primera, la palara se repite %d veces,en la segunda, %d",a,b);
    if(c==1)
    printf("\n las frases son iguales");
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
int bool_palabra(char a[1001],char b[1001])
{
    int x,y,z=0;
    for(x=0;a[x]!='\0';x++);
    for(y=0;b[y]!='\0';y++)
    {
        if(a[y]==b[y]||a[y]==b[y]-32||a[y]==b[y]+32)
        z++;
    }
    if(z==x)
    return 1;
    return 0;
}
int frase_palabra(char x[1001],char f[1001])
{
    char n[1001];
    int a,b,c=0,d=0;
    for(a=0;f[a]!='\0';a++)
    {
        if((f[a]>='a'&&f[a]<='z')||(f[a]>='A'&&f[a]<='Z'))
        {
            b=1;
            n[d]=f[a];
            d++;
        }
        if((f[a]<'a'||f[a]>'z')&&(f[a]<'A'||f[a]>'Z')&&(b==1))
        {
            n[d]='\0';
            c+=bool_palabra(x,n);
            d=0;
            b=0;
        }
    }
    return c;
}
int frases (char x[1001],char y[1001])
{
    int b,d,e=0,n=0,l=0,w=0,t=0,q=0;
    char p[1001],r[1001];
    for(d=0;x[d]!='\0';d++)
    {
        if((x[d]>='a'&&x[d]<='z')||(x[d]>='A'&&x[d]<='Z'))
        {
            b=1;
            r[e]=x[d];
            e++;
        }
        if((x[d]<'a'||x[d]>'z')&&(x[d]<'A'||x[d]>'Z')&&(b==1))
        {
            r[e]='\0';
            w++;
            b=0;
            e=0;
            while(y[n]!='\0')
            {
                if((y[n]>='a'&&y[n]<='z')||(y[n]>='A'&&y[n]<='Z'))
                {
                    l=1;
                    p[t]=y[n];
                    t++;
                }
                if((y[n]<'a'||y[n]>'z')&&(y[n]<'A'||y[n]>'Z')&&(l==1))
                {
                    p[t]='\0';
                    t=0;
                    l=0;
                    break;
                }
                n++;
            }
            q+=bool_palabra(r,p);
        }
    }
    if(q==w)
    return 1;
    return 0;
}
