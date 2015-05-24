//http://www.codechef.com/problems/TREEROOT
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,i,answer=0,j,k;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&j,&k);
            answer += j;
            answer -= k;
        }
        printf("%d\n",answer);
    }
    return 0;
}
