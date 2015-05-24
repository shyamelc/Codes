//https://www.hackerrank.com/contests/interfacecse-codedash/challenges/code1

#include <stdio.h>
#include <stdlib.h>

char input[1005],output[1005];
int arr[150] = {0};

int main()
{
    int n,i,oi=0;
    scanf("%d",&n);
    scanf("%s",input);

    for(i=0;i<n;i++)
    {
        if(!arr[input[i]])
        {
            arr[input[i]] = 1;
            output[oi++] = input[i];
        }
    }
    output[oi] = '\0';
    printf("%s\n",output);
    return 0;
}
