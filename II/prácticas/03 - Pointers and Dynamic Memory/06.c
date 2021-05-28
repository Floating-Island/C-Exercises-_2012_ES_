#include <stdio.h>
#include <stdlib.h>
typedef struct {
int n,o,p,q,r,s,t,u,v,w,x,y,z;
char p1[100],p2[200],p3[300],p4[400];
double a,b,c,d,e,f,g,h,i,j,k,l,m;
} t_varios;

void f_swapstruct(t_varios*,t_varios*);

int main()
{

    t_varios str1,str2;
    str1.f=3.4;
    f_swapstruct(&str1,&str2);
    printf("%lf",str2.f);
    return 0;
}

void f_swapstruct(t_varios* a,t_varios* b)
{
    t_varios c;
    c=*a;
    *a=*b;
    *b=c;
    return;
}
