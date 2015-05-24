#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char arr[20009];

int main()
{
    scanf("%s",arr);
    int test,m,l,length,i,j,ans=0;

    scanf("%d",&test);
    while(test--)
    {
        ans = 0;
        scanf("%d %d",&m,&l);
        int moded = arr[0] - 48;
        if(moded==l)
            ans++;
        for(i=1; arr[i]!='\0';i++)
        {
            int x = arr[i] - 48;
                                    //printf("old mode of %d %d      %d\n",i,moded,x);
            moded = (moded*10 + x) % m;
                                    printf("new mode of %d %d\n",i+1,moded);
            if(moded==l)
            {
                ans += (i+1)%m;
                ans += ((i+1)/m);
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
