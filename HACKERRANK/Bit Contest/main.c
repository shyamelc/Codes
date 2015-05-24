//https://www.hackerrank.com/contests/csindia/challenges/bcontest
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,count=0,i,xors=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int temp;
        scanf("%d",&temp);

        count = 0;
        while(temp > 0)
        {
            int x = temp %2;
            temp /= 2;
            if(x)
                count++;
        }

        xors ^= count;
    }

    if(xors)
        printf("Shaka :)\n");
    else printf("The other player :(\n");
    return 0;
}
