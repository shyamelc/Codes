#include <iostream>
#include<math.h>

using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        long long n,ans=0;
        cin>>n;
        while(n!=1)
        {
            double power = log2(n);
            long long po = power;
            if(power==po)
                n /= 2;
            else
                n = n-pow(2,po);
            ans++;
        }
        if(ans%2==0)
            cout<<"Richard\n";
        else cout<<"Louise\n";
    }
    return 0;
}
