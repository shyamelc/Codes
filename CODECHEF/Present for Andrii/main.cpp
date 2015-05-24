//http://www.codechef.com/COOK48/problems/RRDAG
#include <iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

short matrix[1505][1505];
using namespace std;

int comp(pair<int,int> f,pair<int,int> s)
{

    if(f.first!=s.first)
        return (f.first < s.first);
    return (f.second < s.second);

}

int main()
{
    int n,i,j,u;
    long long answer=0;
    vector< pair<int,int> > pairs;
    scanf("%d",&n);
    vector<int> outDegrees(n,0);
    vector<int> seen(n,0);
    for(i=0;i<n;i++)
    {
        string str;
        cin>>str;
        for(j=0;j<n;j++)
            if(str[j]=='1')
            {
                matrix[i][j] = 1;
                outDegrees[i]++;
            }
            else matrix[i][j] = 0;
    }


    for(i=0;i<n;i++)
    {
        for(j=n-1;j>=0;j--)
        {
            if(outDegrees[j]==0 && !seen[j])
            {
                u = j;
                break;
            }
        }
                            //printf("u%d ",u);
        seen[u] = 1;

        for(j=0;j<n;j++)
        {
            if(!seen[j] && j!=u && !matrix[j][u])
            {
                answer++;
                //matrix[j][u] = 1;
                //outDegrees[j]++;
                pairs.push_back(make_pair(j,u));
            }
        }

        for(j=0;j<n;j++)
            if(matrix[j][u])
                outDegrees[j]--;

    }
    sort(pairs.begin(),pairs.end(),comp);
    printf("%lld\n",answer);
    for(i=0;i<pairs.size();i++)
        printf("%d %d\n",pairs[i].first+1,pairs[i].second+1);
    return 0;
}
