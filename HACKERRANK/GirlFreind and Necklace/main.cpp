#include <iostream>
#include<limits>
#define MOD 1000000007
using namespace std;

int main()
{
    long test;
    cout<<LONG_LONG_MAX;
    cin>>test;
    while(test--)
    {
        long long n;
        cin>>n;
        n--;
        cout<< (((n%MOD)*(n%MOD) - (n%MOD) + 6)/2)%MOD<<endl;
    }
    return 0;
}
