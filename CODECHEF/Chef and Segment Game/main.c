//http://www.codechef.com/NOV14/problems/CHEFSEG

#include <stdio.h>
#include <stdlib.h>

double l,m,r;

void game(long long node)
{
    if(node == 1)
    {
        m = (l+r)/2;
        return;
    }

    game(node/2);

    if(node & 1 == 1)
        l = m;
    else
        r = m;

    m = (l+r)/2;
}

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        long long x,k;
        l = 0;  m = 0;
        scanf("%lld %lld",&x,&k);
        r = x;
                    //printf("%lf %lf %lf %lld\n",l,m,r,k);
        game(k);
        printf("%lf\n",m);
    }
    return 0;
}
