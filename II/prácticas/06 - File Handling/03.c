#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void comparar(FILE*);
char* copiarpalabra(FILE*);
int bool_palabra(char*,char*);
int longitud(char*);
void agregar(FILE*,char*);
int main()
{
    FILE* t1=NULL;
    comparar(t1);
    return 0;
}
void comparar(FILE* vieja)
{
    int a=1;
    char *t1=NULL,*t2=NULL;
    FILE* nueva=NULL;
    vieja=fopen("t1.txt","r");
    if(vieja==NULL)
        exit(1);
    while(!feof(vieja))
    {
        t1=NULL,t2=NULL;
        nueva=fopen("t2.txt","r");
        if(nueva==NULL)
            exit(2);
        t1=copiarpalabra(vieja);
        printf("\n|%s| ",t1);
        rewind(nueva);
        do
        {
            t2=copiarpalabra(nueva);
            printf(" .%s.",t2);
            if(bool_palabra(t1,t2))
                a=0;
            printf(" %d",a);
        }while(a!=0&&(*t2)!=EOF);
        if(a!=0)
            agregar(nueva,t1);
        a=1;
        free(t1);
        free(t2);
    }
    fclose(nueva);
    fclose(vieja);
}
void agregar(FILE* archivo,char* palabra)
{
    archivo=fopen("t2.txt","a");
    if(archivo==NULL)
        exit(9);
    fputs(palabra,archivo);
    fputs(" ",archivo);
}
char* copiarpalabra(FILE* text)
{
    char *palabra=NULL;
    int pos=0,chara;
    palabra=malloc(sizeof(char));
    if(palabra==NULL)
        exit(2);
    while((chara=fgetc(text))!=EOF)
    {
        if((((char)chara>='a')&&((char)chara<='z'))||(((char)chara>='A')&&((char)chara<='Z')))
        {
            palabra=realloc(palabra,sizeof(char)*(pos+1));
            if(palabra==NULL)
                exit(3);
            *(palabra+pos++)=(char)chara;
        }
        else
        {
            *(palabra+pos)='\0';
            break;
        }
    }
    return palabra;
}
int bool_palabra(char *a,char *b)
{
    int x,y,z=0;
    for(x=0; *(a+x)!='\0'; x++);
    for(y=0; *(b+y)!='\0'; y++)
    {
        if(*(a+y)==*(b+y)||*(a+y)==*(b+y)-32||*(a+y)==*(b+y)+32)
            z++;
    }
    if(z==x)
        return 1;
    return 0;
}
