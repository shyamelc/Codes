#include <stdio.h>
#include <stdlib.h>

int chocVan[2][100];
int main()
{
    int m;
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        char t;
        scanf("%c",&t);
        if(t=='.')
            chocVan[i] = 0;
        else chocVan[i] = 1;
    }
    return 0;
}
