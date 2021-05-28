#include <stdio.h>
#include <stdlib.h>
int f_cuentabitsde1(int);
int main()
{
    int n;
    printf("ingrese el numero\n");
    scanf("%d",&n);
    n=f_cuentabitsde1(n);
    printf("\nla cantidad de bits de 1 que tiene es: %d",n);
    return 0;
}
int f_cuentabitsde1(int x)
{
    int a,y=0;
    for(a=0;a<32;a++)
    y+=(x&1<<a)>>a&1;
    return y;
}
