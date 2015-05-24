//https://www.hackerrank.com/contests/w7/challenges/die-hard-3

#include <stdio.h>
#include <math.h>
#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)

int gcd(int a, int b)
{
    //printf("gcd %d %d\n",a,b);
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int a,b,c,minNum,mod1,mod2;
        scanf("%d %d %d",&a,&b,&c);
        if((c>a && c>b))
            printf("NO\n");
        else if(c==a || c==b)
            printf("YES\n");
        else
        {
            int g = gcd(a,b);
            //printf("%d\n",g);
            if(c%g == 0)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
