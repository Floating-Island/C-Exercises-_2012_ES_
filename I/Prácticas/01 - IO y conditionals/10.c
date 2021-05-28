#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a,b,c;
    printf("ingrese una letra\n");
    a=getche ();
    printf("\n ingrese otra letra\n");
    b=getche();
    printf("\n ingrese otra mas\n");
    c=getche();
    if (a>='A'&&a<='Z')
    {
        a=a+32;
    }
    if (b>='A'&&b<='Z')
    {
        b=b+32;
    }
    if (c>='A'&&c<='Z')
    {
        c=c+32;
    }
    if(a<=b&&a<=c)
        {
            printf("\n ordenado alfabeticamente queda asi %c",a);
        }
            else
            {
                if(b<=a&&b<=c)
        {
            printf("\n ordenado alfabeticamente queda asi %c", b);
        }
            else
            {
                  printf("\n ordenado alfabeticamente queda asi %c",c);
            }
            }
return 0;
}
