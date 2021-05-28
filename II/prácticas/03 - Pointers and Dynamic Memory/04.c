#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char a;
    int j;
} str;
int main()
{
    str aloc[3];
    char* d=&aloc[0];
    *d=1;
    return 0;
}
