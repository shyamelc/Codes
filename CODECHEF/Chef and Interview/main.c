//http://www.codechef.com/APRIL15/problems/CHEFLCM

#include <stdio.h>
#include <math.h>

int main()
{
    int test;
    long long n,sum,i;
    scanf("%d",&test);
    while(test--)
    {
        sum = 1;
        scanf("%lld",&n);
        if(n!=1)
            sum += n;
        for(i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                sum += i;
                if(n/i != i)
                    sum += n/i;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
