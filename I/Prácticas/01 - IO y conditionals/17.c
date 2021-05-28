#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1,x2,x3,x4;
    double x;
    printf("ingrese la nota del primer parcial:\n");
    scanf("%d",&x1);
    printf("ingrese la nota del segundo parcial:\n");
    scanf("%d",&x2);
    printf("ingrese la nota del tercer parcial:\n");
    scanf("%d",&x3);
    x=(x1+x2+x3)/3;
    if(x1>=4&&x2>=4&&x3>=4&&x>7)
    {
        printf("promociona la materia con %lf",x);
    }
    if(x1>=4&&x2>=4&&x3>=4&&x<=7)
    {
        printf("promedio general :%lf debe rendir el final",x);
    }
    if (x1<4||x2<4||x3<4)
    {
        printf("ingrese la nota del recuperatorio:\n");
        scanf("%d",&x4);
        if(x4>=4)
        {
            x=(x1+x2+x3+x4)/4;
            printf("promedio general: %lf\n",x);
        }
        else
        {
            printf("estas aplazado macho");
        }
    }

    return 0;
}
