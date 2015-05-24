//https://www.hackerrank.com/contests/interfacecse-codedash/challenges/squares2

#include <stdio.h>
#include <math.h>

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        long long a,b,i,ans=0,xa,xb,t;
        scanf("%lld %lld",&a,&b);
        xa = sqrt(a);       xb = sqrt(b);

        for(i=xa;i<=xb;i++)
        {
            t = i*i;
            if(t>=a && t<=b)
                ans++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
