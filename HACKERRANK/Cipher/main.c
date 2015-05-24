//https://www.hackerrank.com/contests/w10/challenges/cipher
#include <stdio.h>
#include <string.h>

char cipher[2*1000002], output[1000005];

int bitvalue(char x)
{
    if(x==48)
        return 0;
    return 1;
}

char cbitvalue(int x)
{
    if(x)
        return 49;
    return 48;
}

int main()
{
    int n,k,len,i,kk=0;
    scanf("%d %d",&n,&k);
    scanf("%s",cipher);

    len = strlen(cipher);
    k--;
    output[0] = cipher[0];
    int rem = bitvalue(cipher[0]);

    for(i=1;i< (len-k);i++)
    {
        if(bitvalue(cipher[i]))
            output[i] = cbitvalue(!rem);
        else output[i] = cbitvalue(rem);

        rem ^= bitvalue(output[i]);

        kk++;
                            //printf("%d %d kk and k\n",kk,k);
        if(kk >= k)
        {
            rem ^= bitvalue(output[kk-k]);
                           // printf("%d %dhi\n",i,rem);
        }
                    //  printf("%d %d hello\n",i,rem);
    }
                                   // printf("\n");
    output[i] = '\0';
    printf("%s\n",output);
    return 0;
}
