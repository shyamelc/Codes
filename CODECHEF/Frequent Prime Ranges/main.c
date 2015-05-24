#include <stdio.h>
#include <math.h>

int primes[100001]={0}, nextPrime[100001]={0}, primeNumbers[100001]={0};

int main()
{
    long long ans;
    primeNumbers[0] = primeNumbers[1] = 0;
    primeNumbers[2] = 1;
    primes[0] = primes[1] = 1;
    int i,j,x;
    for(i=2;i<sqrt(100001);i++)
    {
        for(j=i*i;j<100001;j+=i)
            primes[j] = 1;
    }
                                //printf("5prime %d\n",primes[5]);
    int nexti = 99991;
    for(i=99990;i>=2;i--)
    {
        nextPrime[i] = nexti;
        if(!primes[i])
            nexti = i;
    }
                                      //  printf("testing %d %d %d\n",nextPrime[2],nextPrime[3],nextPrime[5]);
    for(i=3;i<100000;i++)
        if(!primes[i])
            primeNumbers[i] = primeNumbers[i-1] + 1;
        else primeNumbers[i] = primeNumbers[i-1];

    int test,n,k;
    scanf("%d",&test);
    while(test--)
    {
        ans = 0;
        scanf("%d %d",&n,&k);

        if(!k)
        {
            ans = (n-1)*n/2;
            printf("%lld\n",ans);
        }
       else if(primeNumbers[n] < k)
            printf("0\n");
        else
        {
            for(i=2;i<=n;i++)
                if(primeNumbers[i]==k)
                    break;
                                           // printf("firsti %d\n",i);
            ans += n-i+1;
            long long temp = 0;

            for(j=3;j<=n;j++)
            {
                                        //printf("test %d %d %d\n",i,nextPrime[i],primes[j-1]);
                if(!primes[j-1])
                    i = nextPrime[i];
                temp = n - i + 1;

                if(temp <=0 || i>n || !i)
                    break;
                                           // printf("nexti %d %d %lld\n",j,i,temp);
                ans += temp;
            }

            printf("%lld\n",ans);
        }

    }
    return 0;
}
