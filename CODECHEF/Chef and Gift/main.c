//http://www.codechef.com/AUG14/problems/PRGIFT
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,i,k,temp,evens = 0;
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
        {
            scanf("%d",&temp);
            if(temp%2==0)
                evens++;
        }

        if(evens==n && k==0)
           printf("NO\n");
        else if(k<=evens)
            printf("YES\n");
        else
            printf("NO\n");


    }
    return 0;
}
