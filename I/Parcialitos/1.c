#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1,n2,n3;
    printf("ingrese el  1° numero\n");
    scanf("%d", & n1);
    printf("ingrese el 2° numero\n");
    scanf("%d", &n2);
    printf("ingrese el 3° numero\n");
    scanf("%d", &n3);
    if (n2>=n1&&n3>=n1)
    {
        if (n2>=n3)
        {
            printf("ordenados quedan asi %d,%d,%d",n1,n3,n2);
        }
        else
        {
            printf("ordenados quedan asi %d,%d,%d",n1,n2,n3);
        }
    }
    else
    {
        if (n1>=n2&&n3>=n2)
        {
            if(n1>=n3)
            {
                printf("ordenados quedan asi %d,%d,%d",n2,n3,n1);
            }
            else
            {
                printf("ordenados quedan asi %d,%d,%d",n2,n1,n3);
            }
            }
        else
        {
            if (n1>=n2)
            {
                printf("ordenados quedan asi %d,%d,%d",n3,n2,n1);
            }
            else
            {
                printf("ordenados quedan asi %d,%d,%d",n3,n1,n2);
            }
        }
        }
return 0;
}
