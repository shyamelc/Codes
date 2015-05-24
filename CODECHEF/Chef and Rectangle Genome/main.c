//http://www.codechef.com/JULY14/problems/GERALD09
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int i,n,m,k,j;
        scanf("%d %d %d",&n,&m,&k);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                printf("G");
            printf("\n");
        }
    }
    return 0;
}
