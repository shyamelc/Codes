//http://www.codechef.com/FEB15/problems/STRQ
// The four O(n) loops can be written in one loop!
#include <stdio.h>
#include <stdlib.h>
#define len 1000002

long long ch[len]={0},ce[len]={0},cf[len]={0},hc[len]={0},he[len]={0},hf[len]={0},ec[len]={0},eh[len]={0},ef[len]={0},fc[len]={0},fh[len]={0},fe[len]={0};
char input[len];
long long c[len]={0},h[len]={0},e[len]={0},f[len]={0};
long long getvalue(long long p[],long long x)
{
    if(x<0)
        return 0;
    return p[x];
}

int main()
{
    scanf("%s",input);
    long long ans;
    long long i,j,cs=0,firstc=0,firsth=0,firste=0,firstf=0,es=0,hs=0,fs=0,q,l,r;
    if(input[0]=='c')
        c[0]++;
    else if(input[0]=='h')
        h[0]++;
    else if(input[0]=='e')
        e[0]++;
    else
        f[0]++;
    for(i=1;input[i]!='\0';i++)
    {
        c[i] = c[i-1];  h[i] = h[i-1];  e[i] = e[i-1];  f[i] = f[i-1];
        if(input[i]=='c')
            c[i]++;
         else if(input[i]=='h')
            h[i]++;
        else if(input[i]=='e')
            e[i]++;
        else
            f[i]++;
    }
    char a[2],b[2];

    //ch section
    for(i=0; input[i]!='\0'; i++)
    {
        if(input[i]=='c')
        {
            firstc = i;
            break;
        }
    }
    cs = 1;
    for(j=firstc+1; input[j]!='\0'; j++)
    {
        ch[j] = ch[j-1];
        if(input[j]=='c')
            cs++;
        else if(input[j]=='h')
            ch[j] += cs;
    }

     //ce section
    cs = 1;
    for(j=firstc+1; input[j]!='\0'; j++)
    {
        ce[j] = ce[j-1];
        if(input[j]=='c')
            cs++;
        else if(input[j]=='e')
            ce[j] += cs;
    }

     //cf section
    cs = 1;
    for(j=firstc+1; input[j]!='\0'; j++)
    {
        cf[j] = cf[j-1];
        if(input[j]=='c')
            cs++;
        else if(input[j]=='f')
            cf[j] += cs;
    }

    //hc section

    for(i=0; input[i]!='\0'; i++)
    {
        if(input[i]=='h')
        {
            firsth = i;
            break;
        }
    }
    hs = 1;
    for(j=firsth+1; input[j]!='\0'; j++)
    {
        hc[j] = hc[j-1];
        if(input[j]=='h')
            hs++;
        else if(input[j]=='c')
            hc[j] += hs;
    }

    //he section
    hs = 1;
    for(j=firsth+1; input[j]!='\0'; j++)
    {
        he[j] = he[j-1];
        if(input[j]=='h')
            hs++;
        else if(input[j]=='e')
            he[j] += hs;
    }

    //hf section
    hs = 1;
    for(j=firsth+1; input[j]!='\0'; j++)
    {
        hf[j] = hf[j-1];
        if(input[j]=='h')
            hs++;
        else if(input[j]=='f')
            hf[j] += hs;
    }

    //ec section
    for(i=0; input[i]!='\0'; i++)
    {
        if(input[i]=='e')
        {
            firste = i;
            break;
        }
    }
    es = 1;
    for(j=firste+1; input[j]!='\0'; j++)
    {
        ec[j] = ec[j-1];
        if(input[j]=='e')
            es++;
        else if(input[j]=='c')
            ec[j] += es;
    }

    //eh section
     es = 1;
    for(j=firste+1; input[j]!='\0'; j++)
    {
        eh[j] = eh[j-1];
        if(input[j]=='e')
            es++;
        else if(input[j]=='h')
            eh[j] += es;
    }
    //ef section
     es = 1;
    for(j=firste+1; input[j]!='\0'; j++)
    {
        ef[j] = ef[j-1];
        if(input[j]=='e')
            es++;
        else if(input[j]=='f')
            ef[j] += es;
    }

    //fc section
    for(i=0; input[i]!='\0'; i++)
    {
        if(input[i]=='f')
        {
            firstf = i;
            break;
        }
    }
    fs = 1;
    for(j=firstf+1; input[j]!='\0'; j++)
    {
        fc[j] = fc[j-1];
        if(input[j]=='f')
            fs++;
        else if(input[j]=='c')
            fc[j] += fs;
    }
    //fh section
    fs = 1;
    for(j=firstf+1; input[j]!='\0'; j++)
    {
        fh[j] = fh[j-1];
        if(input[j]=='f')
            fs++;
        else if(input[j]=='h')
            fh[j] += fs;
    }

    //fe section
    fs = 1;
    for(j=firstf+1; input[j]!='\0'; j++)
    {
        fe[j] = fe[j-1];
        if(input[j]=='f')
            fs++;
        else if(input[j]=='e')
            fe[j] += fs;
    }

    scanf("%lld",&q);
    while(q--)
    {
        ans = 0;
        scanf("%s %s",a,b);
        scanf("%lld %lld",&l,&r);
        l--;        r--;
        if(a[0]=='c')
        {
            if(b[0]=='h')
            {
                ans = ch[r]-getvalue(ch,l-1)-getvalue(c,l-1)*(h[r]-getvalue(h,l-1));
                printf("%lld\n",ans);
            }

            else if(b[0]=='e')
            {
                ans = ce[r]-getvalue(ce,l-1)-getvalue(c,l-1)*(e[r]-getvalue(e,l-1));
                printf("%lld\n",ans);
            }

            else
            {
                ans = cf[r]-getvalue(cf,l-1)-getvalue(c,l-1)*(f[r]-getvalue(f,l-1));
                printf("%lld\n",ans);
            }

        }
        else if(a[0]=='h')
        {
            if(b[0]=='c')
            {
                 ans = hc[r]-getvalue(hc,l-1)-getvalue(h,l-1)*(c[r]-getvalue(c,l-1));
                 printf("%lld\n",ans);
            }

            else if(b[0]=='e')
            {
                ans = he[r]-getvalue(he,l-1)-getvalue(h,l-1)*(e[r]-getvalue(e,l-1));
                printf("%lld\n",ans);
            }

            else
            {
                ans = hf[r]-getvalue(hf,l-1)-getvalue(h,l-1)*(f[r]-getvalue(f,l-1));
                 printf("%lld\n",ans);
            }

        }
        else if(a[0]=='e')
        {
            if(b[0]=='c')
            {
                ans = ec[r]-getvalue(ec,l-1)-getvalue(e,l-1)*(c[r]-getvalue(c,l-1));
                printf("%lld\n",ans);
            }

            else if(b[0]=='h')
            {
                ans = eh[r]-getvalue(eh,l-1)-getvalue(e,l-1)*(h[r]-getvalue(h,l-1));
                printf("%lld\n",ans);
            }

            else
            {
                ans = ef[r]-getvalue(ef,l-1)-getvalue(e,l-1)*(f[r]-getvalue(f,l-1));
                printf("%lld\n",ans);
            }

        }
        else
        {
            if(b[0]=='c')
            {
                ans = fc[r]-getvalue(fc,l-1)-getvalue(f,l-1)*(c[r]-getvalue(c,l-1));
                printf("%lld\n",ans);
            }

            else if(b[0]=='e')
            {
                ans = fe[r]-getvalue(fe,l-1)-getvalue(f,l-1)*(e[r]-getvalue(e,l-1));
                printf("%lld\n",ans);
            }

            else
            {
                ans = fh[r]-getvalue(fh,l-1)-getvalue(f,l-1)*(h[r]-getvalue(h,l-1));
                printf("%lld\n",ans);
            }
        }
    }

    return 0;
}
