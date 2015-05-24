#include <iostream>
#define MAX 10000000001
using namespace std;

bool fibo[10000000002 ] = {0};

int main()
{
    fibo[0] = fibo[1] = true;

    long long f1 = 0,f2 = 1,f=0;

    while(f <= MAX)
    {
        f = f1+ f2;
        f1 = f2;
        f2 = f;
        fibo[f] = true;
    }

    for(int i=0;i<50;i++)
        if(fibo[i])
            cout<<i<<" ";
    return 0;
}
