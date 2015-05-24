#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int arr[1000000];

        int temp=0,filled=0,firstdone = 0;
        char t;
        scanf("%c",&t);

        while(t!='\0')
        {

           if(t=='+')
           {
               arr[filled++] = -1;
               if(!firstdone)
                    temp
           }
           else if(t=='*')
           {
                arr[filled++] = -2;
           }

        }
    }
    return 0;
}
