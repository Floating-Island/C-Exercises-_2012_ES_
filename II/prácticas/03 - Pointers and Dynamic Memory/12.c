#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int a,b;
}t_dosint;

void f_cambio(int*,int*);

int main()
{
    t_dosint s;
    s.a=2;
    s.b=7;
    f_cambio(&(s.a),&(s.b));
    printf("%d %d\n",s.a,s.b);
    return 0;
}
void f_cambio(int* a,int* b)
{
int x;
x=*a;
*a=*b;
*b=x;
return;
}
