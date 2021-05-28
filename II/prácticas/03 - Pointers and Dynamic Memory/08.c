#include <stdio.h>
#include <stdlib.h>
char* f_espdin(char*);
int main()
{
char p[]={"hola, como esta voce ce ce"};
char* s=NULL;
s=f_espdin(p);
printf("%s",s);
    return 0;
}

char* f_espdin(char* a)
{
    int aux=0;
    char* txt=NULL;
    txt=malloc(sizeof(char));
    for(aux=0;*(a+aux)!='\0';aux++)
        {
            if(aux!=0)
            txt=realloc(txt,sizeof(char)*(aux+1));
            *(txt+aux)=*(a+aux);
            if(txt==NULL)
            exit(0);
        }
        *(txt+aux)='\0';
    return   txt;
}
