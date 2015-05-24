//http://www.codechef.com/NOV14/problems/PRPALN

//This solution gets full points
#include <stdio.h>
#include <string.h>

char input[100005];
int discontinous[2] = {0};

int palinOdd = 0;
void giveDiscont(char *in, int len)
{
    palinOdd = 0;
    discontinous[0] = discontinous[1] = -1;
    int i=0, j = len-1;

    for(; i != len/2; i++,j--)
    {
        if(in[i] != in[j])
        {
            discontinous[0] = i;        discontinous[1] = j;
            return;
        }
    }

    if(discontinous[0] == -1 && len & 1 == 1)
        palinOdd = 1;
}

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

int main()
{

    int test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%s",input);
        int length = strlen(input);
        giveDiscont(input,length);
                    //printf("discont %d %d\n",discontinous[0],discontinous[1]);
        if(palinOdd || isPalindrome(input,discontinous[0],length) || isPalindrome(input,discontinous[1],length))
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
