#include <iostream>
#include<map>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    long arr[n];
    long long maxTemp = 0;
    map<int,long> divide;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        int by2 = arr[i]/2;
        if(divide.find(by2)!=divide.end())
            divide[arr[i]] = by2;
        else
        {
           long long Temp = divide[by2] & arr[i];
           if (Temp>maxTemp)
            maxTemp=Temp;
        }
    }
    printf("%lld\n",maxTemp);
    return 0;
}
