#include <stdio.h>
#include <stdlib.h>

char arr[105];
int main()
{
    int test,n,i,len,maxRepeat;
    long long ans;
    scanf("%d",&test);
    while(test--)
    {
        len = ans = 0;
        scanf("%s",arr);
        scanf("%d",&n);
        n *= 12;
        for(i=0;arr[i]!='\0';i++)
        {
            if(arr[i]=='T')
                len += 2;
            else len++;
        }
        maxRepeat = n/len;
        for(i=1;i<=n;i++)
        {
            ans += (n-i)/len;
           // printf("%d %d\n",i,(n-i+1)/len);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
