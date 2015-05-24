//http://www.codechef.com/FEB15/problems/CHEFEQ

#include<stdio.h>
#include<math.h>

int main()
{
    int test;
    long long n,s,i,ogsum,left;
    double root,x;
    scanf("%d",&test);
    while(test--)
    {
        root = 0;
        scanf("%lld %lld",&n,&s);
        ogsum = n*(n+1)/2;
        if(n*(n+1)/2==s)
        {
            printf("0\n");
            continue;
        }
        root = (-1+sqrt(1+8*s))/2;
                                        //printf("%lf hi\n",root);
        i = root;
        left = s - i*(i+1)/2;
                                       // printf("%lld %lld check\n",left,i);
        for(;left<n-i; )
        {
                                    //printf("in the\n");
            i--;
            left = s - i*(i+1)/2;
        }

        printf("%lld\n",n-i);
    }
    return 0;
}
