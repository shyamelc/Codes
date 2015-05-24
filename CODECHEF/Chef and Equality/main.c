//http://www.codechef.com/FEB15/problems/CHEFEQ

#include <stdio.h>
#include <stdlib.h>

int freq[100005]={0};

int main()
{
    int test,n,i,maxfreq,temp;
    scanf("%d",&test);
    while(test--)
    {
        maxfreq = 0;
        memset(freq,0,sizeof(freq));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&temp);
            freq[temp]++;
            if(freq[temp] > maxfreq)
                maxfreq = freq[temp];
        }

        printf("%d\n",n-maxfreq);
    }
    return 0;
}
