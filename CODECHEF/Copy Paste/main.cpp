//http://www.codechef.com/COOK48/problems/RRCOPY
#include <iostream>
#include<map>

using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        map<int,int> arr;
        for(int i=0; i<n; i++)
            {
                int temp;
                cin>>temp;
                arr[temp] = 0;
            }
            cout<<arr.size()<<endl;
    }
    return 0;
}
