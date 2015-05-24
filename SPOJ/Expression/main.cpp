#include <stdio.h>
#include <stack>

using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        stack<long long> stk1,stk2;
        //stk1.push(0);   stk1.push(-1);   stk2.push(1);  stk2.push(-2);
        long long temp=0,temp1,temp2,j=0,minans=0,maxans=0;
        char t,arr[1000000];
        scanf("%s",arr);
        t = arr[0];
        while(t != '\0')
        {
                                            //printf("%c\n",t);
            if(t=='+' || t=='*')
            {
                                            //printf("hidd\n");
                temp1 = temp;   temp2 = temp;
                                            stk1.empty();
                                            //printf("hi\n");
                if(!stk1.empty() && stk1.top()==-1)
                {
                                            //printf("%d\n",stk1.top());
                    stk1.pop();
                    temp1 = stk1.top() + temp;
                    stk1.pop();
                    //stk1.push(temp1);
                }

                if(!stk2.empty() && stk2.top()==-2)
                {
                    stk2.pop();
                    temp2 = stk2.top()*temp;
                    stk2.pop();
                    //stk2.push(temp2);
                }
                if(t=='+')
                {

                stk1.push(temp1);
                stk2.push(temp2);
                temp = 0;
                stk1.push(-1);
                stk2.push(-1);
                }
                else
                {
                stk1.push(temp1);
                stk2.push(temp2);
                temp = 0;
                stk1.push(-2);
                stk2.push(-2);
                }

            }

           else
               temp = (temp*10) + (t-48);

            t = arr[++j];
        }

         temp1 = temp;       temp2 = temp;
        if(!stk1.empty() && stk1.top()==-1)
                {
                                            //printf("%d\n",stk1.top());
                    stk1.pop();
                    temp1 = stk1.top() + temp;
                    stk1.pop();
                    //stk1.push(temp1);
                }

        if(!stk2.empty() && stk2.top()==-2)
                {
                    stk2.pop();
                    temp2 = stk2.top()*temp;
                    stk2.pop();
                    //stk2.push(temp2);
                }

        stk1.push(temp1);       stk2.push(temp2);


        maxans = stk1.top();            stk1.pop();         //printf("%d\n",maxans);
        minans = stk2.top();            stk2.pop();

       /* while(!stk1.empty())
        {
            printf("%d ",stk1.top());
            stk1.pop();
        }*/
        while(!stk1.empty())
        {
            long long x = stk1.top();       stk1.pop();
            if(x != -2)
            {

                maxans *= x;
               // printf("%d ",maxans);
            }

        }
            //printf("\n\n");
        while(!stk2.empty())
        {
            long long x = stk2.top();       stk2.pop();
            if(x != -1)
                minans += x;
        }
        if(minans > maxans)
        {
            long long temp = minans;
            minans = maxans;
            maxans = temp;
        }
        printf("%lld %lld\n",minans,maxans);
    }
    return 0;
}
