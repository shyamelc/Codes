//https://www.hackerrank.com/contests/w10/challenges/alternating-characters
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        char arr[100005];
        scanf("%s",arr);
        int i=0,j,ans = 0;
        char t = arr[0],x=arr[1];

        while(t!='\0')
        {
            for(j=i+1; x!='\0';j++)
            {
                x = arr[j];
                if(x==arr[i])
                {
                                            //printf("%d %d\n",i,j);
                    ans++;
                }
                else
                {
                    i = j-1;
                    break;
                }

            }
            t = arr[++i];
        }

        printf("%d\n",ans);
    }
    return 0;
}
