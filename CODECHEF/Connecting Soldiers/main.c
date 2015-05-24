#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        int maxi = (n*(n+1))/2 + n,answer = 0;
        int mini = maxi - n + 2;
        if(m<mini)
            printf("-1\n");
        else
        {
            int i;
            for(i=maxi;i>mini;i--)
                if(i<=m)
                {
                    answer = m-i;
                    break;
                }
            printf("%d\n",answer);
        }
    }
    return 0;
}
