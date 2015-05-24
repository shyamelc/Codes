//http://www.codechef.com/FEB15/problems/CHEFCH

#include <stdio.h>
#include <stdlib.h>

char inpu[100005];

int main()
{
    int test,ans,i,ans2;
    scanf("%d",&test);
    while(test--)
    {
        ans = 0;    ans2=0;
        scanf("%s",inpu);

        for(i=0; inpu[i]!='\0'; i++)
        {
            if(i%2==0 && inpu[i]!='+')
                ans++;
            if(i%2!=0 && inpu[i]!='-')
                ans++;

            if(i%2!=0 && inpu[i]!='+')
                ans2++;
            if(i%2==0 && inpu[i]!='-')
                ans2++;
        }

        if(ans < ans2)
            printf("%d\n",ans);
        else printf("%d\n",ans2);
    }
    return 0;
}
