//https://www.hackerrank.com/contests/csindia14-qr1/challenges/broken-keyboard
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int test;
    scanf("%d",&test);
    while(test--)
        {
        int broken=0,i,count=0;
        char bstring[30],word[105];
        scanf("%s",bstring);

        for(i=0;bstring[i]!='\0';i++)
        {
            broken = broken | (1<<(bstring[i]-97));
            //printf("%d %dhi\n",bstring[i]-97,broken);
        }

        scanf("%s",word);
        for(i=0;word[i]!='\0';i++)
            {
            if(broken & (1<<(word[i]-97)))
                {
                count++;
                broken = broken & (~(1<<(word[i]-97)));
                //printf("%dhell\n",broken);
            }
        }
        printf("%d\n",count);
    }


    return 0;
}
