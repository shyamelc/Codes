//http://www.codechef.com/DINP1501/problems/FIBGCD

#include <stdio.h>
#include <stdlib.h>
#define mod 1000000007

int fibos[1000002]={0};

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main()
{
    int i;
    fibos[1] = 1;
    for(i=2;i<=1000000;i++)
        fibos[i] = (fibos[i-1]%mod + fibos[i-2]%mod)%mod;
    int test,a,b;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",fibos[gcd(a,b)]);
    }
    return 0;
}
