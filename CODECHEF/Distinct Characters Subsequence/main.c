//http://www.codechef.com/NOV14/problems/DISCHAR
#include <stdio.h>
#include <stdlib.h>

char input[100005];

int main()
{
    int test;
    scanf("%d",&test);

    while(test--)
    {

        scanf("%s",input);
        int mask = 0,i,ans=0;

        for(i=0; input[i] != '\0'; i++)
        {
            if(!(mask & (1<<(input[i]-97))))
            {
                ans++;
                mask = mask | (1<<(input[i]-97));
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
