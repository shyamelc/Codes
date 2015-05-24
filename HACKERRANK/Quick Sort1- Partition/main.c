//https://www.hackerrank.com/contests/interfacecse-codedash/challenges/quicksort1
//piece of cake

#include <stdio.h>
#include <stdlib.h>

int main()
{

    {
        int n;
        scanf("%d",&n);
        int arr[n],first[n],second[n],i,fi=0,si=0;
        for(i=0;i<n;i++)
            scanf("%d",arr+i);
        for(i=1;i<n;i++)
            if(arr[i] < arr[0])
                first[fi++] = arr[i];
            else    second[si++] = arr[i];

        for(i=0;i<fi;i++)
            printf("%d ",first[i]);
        printf("%d ",arr[0]);
        for(i=0;i<si;i++)
            printf("%d ",second[i]);
    }
    return 0;
}
