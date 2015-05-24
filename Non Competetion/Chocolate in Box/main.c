#include <stdio.h>
#include <stdlib.h>

int main()
{
    long n,i;
    scanf("%ld",&n);
    long answer,temp;
    scanf("%ld",&answer);
    for(i=1;i<n;i++)
    {
        scanf("%ld",&temp);
        answer ^= temp;
    }
    printf("%ld\n",answer);
    return 0;
}
