//https://www.hackerrank.com/contests/interfacecse-codedash/challenges/anagram

#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<math.h>

char str[10002];
int hashia[26],hashib[26];
int main()
{
    int test,i,ans;
    scanf("%d",&test);
    while(test--)
    {
        for(i=0;i<26;i++)
            hashia[i] = hashib[i] = 0;
        scanf("%s",str);
        int l = strlen(str);
        if(l&1)
            printf("-1\n");
        else
        {
            ans = 0;
            for(i=0;i<l/2;i++)
                hashia[str[i]-97]++;
            for(i=l/2;i<l;i++)
                hashib[str[i]-97]++;
            for(i=0;i<26;i++)
                ans += abs(hashia[i]-hashib[i]);
            printf("%d\n",ans/2);

        }
    }
    return 0;
}
