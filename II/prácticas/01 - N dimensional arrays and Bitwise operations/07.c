#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
int main()
{
    int x;
    char a;
    printf("Ingrese una letra \n");
    a=getche();
    printf("\n");
    for(x=7;x>=0;x--)
        printf("%d",(a&(int)pow(2,x)?1:0));
    return 0;
}
