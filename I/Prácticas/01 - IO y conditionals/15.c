#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d,m,a,x1b,x2b,x3b,x1nb,x2nb,x3nb,x1bf,x1nbf;
    printf("ingrese un dia: \n");
    scanf("%d",&d);
    printf("ingrese un mes:\n");
    scanf("%d",&m);
    printf("ingrese un año: \n");
    scanf("%d",&a);
    if ((a%4==0&&a%100!=0)||a%400==0)
    {
        x3b=1;
        if (m==2)
        {
            x2b=1;
            if(d>=1&&d<=29)
            {
                x1bf=1;
            }
        }
    }
    else
    {
        x3nb=1;
        if(m==2)
        {
            x2nb=1;
        if (d>=1&&d<=28)
        {
            x1nbf=1;
        }
        }


    }
        if (m%2==0&&m!=2&&m!=8&&m!=10&&m!=12)
        {
            x2b=1;
            x2nb=1;
            if(d>=1&&d<=30)
            {
                x1b=1;
                x1nb=1;
            }
        }
        if((m%2!=0)||(m==8)||(m==10)||(m==12))
        {
            x2nb=1;
            x2b=1;
           if (d>=1&&d<=31)
           {
               x1b=1;
               x1nb=1;
           }
        }
        if ((x3b==1&&(x1bf==1||x1b==1)&&x2b==1)||(x3nb==1&&(x1nb==1||x1nbf==1)&&x2nb==1))
        {
            printf("%d/%d/%d  es correcto",d,m,a);
        }
        else
        {
            printf("%d/%d/%d  no es correcto",d,m,a);
        }
    return 0;
}
