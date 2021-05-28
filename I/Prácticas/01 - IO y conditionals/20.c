#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a,b,c;
    printf("es de maniana?\n");
    a=getche();
    printf("\nEl llamado es de tu casa?\n");
    b=getche();
    printf("\nEstas en clase?\n");
    c=getche();
    if(c=='s'||c=='S')
    {
        printf("\nno debe atender");
    }
    else
    {
        if (a=='s'||a=='S')
        {
            if (b=='s'||b=='S')
            {
                printf("\ndebe atender");
            }
            else
            {
                printf("\nno debe atender");
            }
        }
        else
        {
            printf("\ndebe atender");
        }
    }

    return 0;
}
