#include <stdio.h>
#include <string.h>

char arr[1002];

int palindrome(char *s,int length)
{
    int i,j,x,y,reg;
    for(i=0;i<length;i++)
        for(j=i+1;j<length;j++)
        {
            reg = 1;
                               // printf("%dx %dy\n",i,j);
            for(x=i,y=j;y-x!=(-1) && x!=y;x++,y--)
            {

                if(s[x]!=s[y])
                {
                    reg = 0;
                    break;
                }
            }
            if(reg)
                return 1;
        }

        return 0;
}

int main()
{
    int n,p,i,j,answer = 0,length,x;
    scanf("%d %d",&n,&p);
    p += 96;
    scanf("%s",arr);
    length = strlen(arr);


    for(i=length-1;i>=0;i--)
    {
        h :
        if(arr[i]+1 > p)
            for(j=i,x=97;j<length;j++,x++)
            {
                arr[i] = x;
                if(x > p)
                    break;
            }

        else
        {
            arr[i]++;
            if(palindrome(arr,length))
            {
                               // printf("%s pali\n",arr);
                goto h;
            }
            else
            {
                               // printf("%s not\n",arr);
                answer = 1;
                break;
            }
        }
    }

    if(answer)
        printf("%s\n",arr);
    else printf("NO\n");
    return 0;
}
