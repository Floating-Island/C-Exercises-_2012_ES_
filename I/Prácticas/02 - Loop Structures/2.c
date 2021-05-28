#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,num=1, div, cont=0;
    while (cont<4)
    {
        div=1;
        x=0;
        while (num>div)
        {
            if (num%div==0)
            {
                x=x+div;
            }
        div++;
        }
        if (num==x)
            {
                printf("%d ",num);
            cont++;
            }
    num++;
    }
    return 0;
}
