//http://codeforces.com/contest/545/problem/B

#include <stdio.h>
#include <stdlib.h>
#define LEN 100002
char s[LEN],t[LEN],p[LEN];

int main()
{
    scanf("%s",s);
    scanf("%s",t);
    int a=0,b=0,i,sp=0,tp=0;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]==t[i])
            p[i] = s[i];
        else
        {
            if(a==b)
            {
                p[i] = '0';
                if(s[i]=='0')
                {
                    b++;
                    tp++;
                }
                else
                {
                    a++;
                    sp++;
                }
            }
            else
            {
                if(a > b)
                {
                    p[i] = s[i];
                    b++;
                    tp++;
                }
                else
                {
                    p[i] = t[i];
                    a++;
                    sp++;
                }
            }
        }

            //printf("p[i] %d %c\n",i,p[i]);
    }
    p[i] = '\0';
    if(tp==sp)
        printf("%s",p);
    else printf("impossible");
    return 0;
}
