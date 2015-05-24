//https://www.hackerrank.com/contests/101aug14/challenges/pangrams

#include <stdio.h>
#include <stdlib.h>

char arr[1005];
int all = 134217726, answer = 0;
int main()
{
    scanf("%[^\n]s",arr);
    int i=0;
    char temp = arr[i];

    while(temp!='\0' && answer!=all)
    {

        if(temp < 91 && temp > 64)
            temp -= 64;
        else if(temp < 123 && temp > 60)
            temp -= 96;
        else
        {
            temp = arr[++i];
            continue;
        }

        answer = answer | (1<<temp);
                               // printf("set bit %d %c %d\n",temp,temp+64,answer);
        temp = arr[++i];

    }

    if(answer==all)
        printf("pangram\n");
    else printf("not pangram\n");
    return 0;
}
