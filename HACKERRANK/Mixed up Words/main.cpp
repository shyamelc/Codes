//https://www.hackerrank.com/contests/codenite1/challenges/mixed-up-words
#include <iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        string inp;
        vector<int> small,large;
        cin>>inp;
        for(int i=0;i<inp.length();i++)
        {
            if(97<=inp[i] && inp[i]<=122)
                small.push_back(i);
            else   large.push_back(i);
        }
                                    //cout<<small.size()<<" "<<large.size()<<endl;
        if(small.size() >= large.size())
        {
            for(int i=0;i<large.size();i++)
                inp[large[i]] += 32;
        }
        else
            for(int i=0;i<small.size();i++)
                inp[small[i]] -= 32;
        cout<<inp<<endl;
    }
    return 0;
}
