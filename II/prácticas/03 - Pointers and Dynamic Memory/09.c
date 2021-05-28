#include <stdio.h>
#include <stdlib.h>
#define N 4

char* subcadena(char* ,unsigned int ,unsigned int );
int main()
{
    char *s;
    char *p="universidad catolica argentina";
    s=subcadena(p,8,5);
    printf("\n%s",s);
    return 0;
}
char* subcadena(char* p,unsigned int i,unsigned int n)
{
    char* s=NULL;
    int cont=1,cont2;
    for(cont2=0;*(p+cont2)!='\0';cont2++);
    if(cont2<i)
    return s;
    s=malloc(sizeof(char)*N);
    do
        {
        *(s+cont-1)=*(p+i+cont-1);
        if(cont>=N&&(i+cont)<(n+1))
        {
        s=realloc(s,sizeof(char)*(cont+N));
        if(s==NULL)
        exit(0);
        }
        cont++;
        }while(cont<=n&&(*(p+cont)!='\0'));
    if(cont<sizeof(s))
            s=realloc(s,sizeof(char)*cont);
    *(s+cont)='\0';
    return s;
}
