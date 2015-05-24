//https://www.hackerrank.com/contests/w13/challenges/taum-and-bday
#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long test,x,y,z,b,w,ans;
    scanf("%lld",&test);
    while(test--)
    {
        ans = 0;
        scanf("%lld %lld",&b,&w);
        scanf("%lld %lld %lld",&x,&y,&z);
        int sel = 0;
        if(y < x)
            sel = 1;

        if(sel)
        {
            ans += (w*y);
            if(y+z < x)
                ans += b*(y+z);
            else
                ans += b*x;
        }
        else
        {
            ans += (b*x);
            if(x+z < y)
                ans += w*(x+z);
            else
                ans += w*(y);
        }

        printf("%lld\n",ans);

    }
    return 0;
}
