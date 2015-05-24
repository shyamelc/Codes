//http://www.codechef.com/NOV14/problems/PRPALN
#include <stdio.h>
#include <string.h>

int isPalindrome(char *str, int notTaken, int length)
{
    int i,j,ans=1,traversed=0;

    for(i=0,j=length-1; traversed != (length-1)/2; )
    {
        if(i==notTaken)
            i++;
        else if(j==notTaken)
            j--;
        else
        {
            traversed++;
            if(str[i] != str[j])
            {
                ans=0;
                break;
            }
            i++;    j--;
        }

    }

    return ans;
}

char input[100005];

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%s",input);
        int length = strlen(input),i,j,ans=0;

        for(j=0;j<length ;j++)
        {
            if(isPalindrome(input, j, length))
            {
                ans = 1;
                break;
            }
        }

        if(ans)
            printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
