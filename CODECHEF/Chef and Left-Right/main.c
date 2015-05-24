//http://www.codechef.com/SEPT14/problems/CHEFLR
#include <stdio.h>
#include <stdlib.h>
#define MAX 100002
#define MODULO 1000000007

int main()
{
    int test,i,odd;
    int answer;
    scanf("%d",&test);
    while(test--)
    {
        odd = 1;
        answer = 1;
        char arr[MAX];
        scanf("%s",arr);
        char t = arr[0];
        i = 0;
        while(t!='\0')
        {
                                            //printf("%c %d\n",t,answer);
           answer = (answer<<1)%MODULO;
           if(odd)
           {
              if(t=='r')
                answer += 2;
           }
           else
           {
               if(t=='l')
                answer -= 1;
               else answer += 1;
           }

           odd ^= 1;
           t = arr[++i];
        }

        printf("%d\n",answer);
    }
    return 0;
}
