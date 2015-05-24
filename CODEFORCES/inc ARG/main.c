//http://codeforces.com/contest/465/problem/A
#include <stdio.h>
#include <stdlib.h>

char arr[101];

int main()
{
    int n,i=0,carry = 1, count = 0;
    scanf("%d",&n);
    scanf("%s",arr);

    char t = arr[0];

    while(t!='\0')
    {
        if(t=='0')
        {
            if(carry)
                count++;
            break;
        }
        else
        {
            if(carry)
                count++;
            else break;
        }
        t = arr[++i];
    }

    printf("%d\n",count);
    return 0;
}
