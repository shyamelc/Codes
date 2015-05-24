//http://www.codechef.com/COOK48/problems/RRSUM
#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long n,m;
    scanf("%lld %lld",&n,&m);
    while(m--)
    {
        long long q,dub = 2*n;
        scanf("%lld",&q);
        if(q<n+1 || q>dub+n)
            printf("0\n");
        else if(q<=dub)
            printf("%lld\n",q-n-1);
        else printf("%lld\n",n-(q-dub)+1);

    }
    return 0;
}
