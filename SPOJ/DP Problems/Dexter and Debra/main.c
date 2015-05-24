#include <stdio.h>
#include <stdlib.h>

int arr[100005] = {0},i;
int main()
{
    int test;
    scanf("%d",&test);

    arr[1] = 1; arr[3] = 1; arr[4] = 1;
    for(i=5;i<100005;i++)
        {
            if(!arr[i-4] || !arr[i-1])
                arr[i] = 1;
        }

    while(test--)
    {
        int n;
        scanf("%d",&n);
        if(arr[n])
            printf("Debra\n");
        else    printf("Dexter\n");
    }
    return 0;
}
