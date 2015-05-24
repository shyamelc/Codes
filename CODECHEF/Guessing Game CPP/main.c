//http://www.codechef.com/JUNE14/problems/GUESS
#include <stdio.h>
#include <stdlib.h>


long long gcd(long long a, long long b) {
  long long r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main()
{
    long test;
    scanf("%ld",&test);
    while(test--)
    {
        long long m,n;
        scanf("%lld %lld",&m,&n);
        long long numerator, denominator = m*n;
        numerator = (m-m/2)*(n/2);      numerator += (m/2)*(n-n/2);
        long long divisor = gcd(numerator, denominator);
        numerator /= divisor;   denominator /= divisor;
        printf("%lld/%lld\n",numerator,denominator);
    }
    return 0;
}
