//http://www.codechef.com/SNCK151A/problems/CHEFVOTE

#include <stdio.h>

int input[70]={0},answer[70]={0};
int mark[70] = {0};
int main()
{
    int test,n,i,sum=0,onOf,fill,j,total,start;
    scanf("%d",&test);
    while(test--)
    {
        total = 0;
        fill = 0;
        onOf = 1;
        sum = 0;
        scanf("%d",&n);


        for(i=0;i<n;i++)
        {
            scanf("%d",input+i);
            sum += input[i];
            if(input[i] == n)
                onOf = 0;
        }
        start = 0;
        if(sum != n)
            onOf = 0;

        h:

        total = 0;
        for(i=0;i<n;i++)
        {
            mark[i] = answer[i] =  0;
        }
        if(!onOf)
        {
            printf("-1\n");
            continue;
        }

        else
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<input[i];j++)
                {
                    if(total==n-1 && fill==i)
                    {
                        fill = (start++) + 1;

                        goto h;
                    }
                    if(fill == i)
                        fill = (fill + 1)%n;
                    if(mark[fill]==0)
                    {
                        mark[fill] = 1;
                        answer[fill] = i+1;
                        fill = (fill+1)%n;
                        total++;
                    }
                    else
                    {
                        fill = (fill+1)%n;
                        j--;
                    }
                }

            }

            if(!onOf)
            {
                printf("-1\n");
                continue;
            }

            for(i=0;i<n;i++)
                printf("%d ",answer[i]);
            printf("\n");
        }
    }
    return 0;
}
