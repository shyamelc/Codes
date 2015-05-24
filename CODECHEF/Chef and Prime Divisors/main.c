//http://www.codechef.com/MAY15/problems/CHAPD/

#include <stdio.h>
#include <math.h>

long long test,a,b,previous,i;

long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int ans;
    scanf("%lld",&test);
    while(test--)
    {
        ans = 1;
        scanf("%lld %lld",&a,&b);

        if(a%b==0 || (a&(a-1)==0 && b&(b-1)==0) )
        {
            printf("Yes\n");
            continue;
        }
        long long gcdd = gcd(a,b);
        if(b%2==0)
        {
            if(a%2!=0)
            {
                ans = 0;
            }

            while(b%2==0)
                b /= 2;
        }

        if(ans)
        {
            for(i=3;i<=sqrt(b) && i<=gcdd;i+=2)
            {
                if(b%i==0 && a%i!=0)
                {
                    ans = 0;
                    break;
                }

                while(b%i==0)
                    b /= i;

                if(a%b==0)
                {
                    ans = 1;
                    break;
                }
            }

            if(b > 2 && a%b!=0)
                ans = 0;
        }

        if(ans)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
