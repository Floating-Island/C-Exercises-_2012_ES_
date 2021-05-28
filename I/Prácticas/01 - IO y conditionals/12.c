#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a;
    printf("ingrese una letra minuscula o mayuscula \n");
    a=getche();
    if(a>='A'&&a<='Z')
    {
        a=a+32;
        printf("\n su minuscula es: %c",a);
        a=a-32;
    }
    if(a>='a'&&a<='z')
    {
        a=a-32;
        printf("\n su mayuscula es: %c",a);
    }
if(a=='a'||a=='A'||a=='e'||a=='E'||a=='i'||a=='I'||a=='o'||a=='O'||a=='u'||a=='U')
{
    printf("\n es una vocal");
}
else
{
   if (!((a>='A'&&a<='Z')||(a>='a'&&a<='z')))
   {
       printf("\n no es una letra");
   }
else
{
    printf("\n es una consonante");
}
}
    return 0;
}
