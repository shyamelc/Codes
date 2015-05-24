#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        long n,i,answer=1;
        scanf("%ld",&n);
        if(n%2 != 0)
            printf("0\n");
        else
        {
            for(i=2;i<=sqrt(n);i++)
            {
                if(n%i==0)
                {
                    if(i%2==0)
                        answer++;
                    long x = n/i;
                    if(x%2==0 && x!=i)
                        answer++;
                }
            }
            printf("%ld\n",answer);
        }
    }

    return 0;
}
