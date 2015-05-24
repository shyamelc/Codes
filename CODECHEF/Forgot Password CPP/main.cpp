//http://www.codechef.com/JUNE14/problems/FORGETPW
#include <iostream>
#include<map>
#include<string.h>

using namespace std;

long length;
bool decimalPoint = false;
char* prevTrim(char* in)
{
    if(in[0]=='0' && in[1]=='.')
        in++;
    else
    {
        while(in[0]=='0')
            in++;
    }
    return in;
}

void afterTrim(char *in)
{
    if(decimalPoint && in[length-1]=='0')
    {
        long i;
        for(i = length-1; i>0; i--)
        {
            if(in[i]!='0')
                break;
        }
        if(in[i]!='.')
            in[i+1] = '\0';
        else
            in[i] = '\0';
    }
}
int main()
{
    int test;   cin>>test;
    while(test--)
    {
        length = 0;
        decimalPoint = false;
        int noRules;    cin>>noRules;
        map<char,char> rules;
        for(int i=0; i<noRules; i++)
        {
            char a,b;   cin>>a>>b;
            rules[a] = b;
        }
        char input[1000008];   cin>>input;
        length = strlen(input);
        for(long i=0; i<length; i++)
        {
            if(rules.count(input[i]) == 1)
                input[i] = rules[input[i]];
            if(input[i]=='.')
                decimalPoint = true;
        }
        //Triming
        char* pTrimed = prevTrim(input);
        afterTrim(input);
                                        length = strlen(pTrimed);
        if(pTrimed[length-1]=='.')
            pTrimed[length-1] = '\0';
        if(strlen(pTrimed)!=0)
            cout<<pTrimed<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0;
}
