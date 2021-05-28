#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1,x2,x4;
    char a;
    double x3;
    printf("ingrese el sueldo:\n");
    scanf("%d",&x1);
    printf("¿Tiene hijos?:\n");
    a=getche();
    printf("\n ingrese categoria (1-9):\n");
    scanf("%d",&x2);
    x4=0;
    if(x1>2000)
    {
        x4=x4+15;
    }
    else
    {
        x4=x4+20;
    if (x2>=1&&x2<=3)
    {
        x4=x4+10;
        if (a=='s')
        {
            x4=x4+5;
        }
    }
    if (x2>=4&&x2<=6)
    {
        x4=x4+12;
        if (a=='s')
        {
            x4=x4+5;
        }
    }
    if (x2>=7&&x2<=9)
    {
        x4=x4+20;
    }
    }
    x3=x1*((x4+100)*0.01);
    printf("sueldo $%d\n",x1);
    printf("¿Hijos?: %c\n", a);
    printf("categoria: %d\n",x2);
    printf("Sueldo total: $%.2lf",x3);
        return 0;
}
