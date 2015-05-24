#include <iostream>
#include<vector>
#include<string>
using namespace std;


int main()
{
    int q;
    string x;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        char op;
        cin>>op;
        int insertOrLength;
        cin>>insertOrLength;

        if(op=='+')
        {
            string temp;
            cin>>temp;
            x.insert(insertOrLength,temp);
        }
        else
        {
            int len;
            cin>>len;
            for(int j=insertOrLength-1,k=0;k<len;k++,j++)
                cout<<x[j];
            cout<<endl;
        }
    }
    return 0;
}
