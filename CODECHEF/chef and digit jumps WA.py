#!/usr/bin/env python3
#http://www.codechef.com/problems/ADIGIT
"""0998887776665554443322223300885577

Correct Ans --> 5

Directions : 0,0(last occurrence),8(next),8(index:5),7(next),7(last)
My output is 6   """
stri = input()
length = len(stri)
digits = [length]*10
dp = list(range(length))
digits[int(stri[0])] = 0
digits[int(stri[1])] = min(digits[int(stri[1])],1)

i = 2
while i!=length-1: 
    dig = int(stri[i])
    
    dp[i] = min(dp[i],dp[i+1]+1,dp[i-1]+1,digits[dig]+1)
    digits[dig] = min(digits[dig], dp[i])
    #print(i,dp[i],dig,digits[dig])
    if dp[i-1] > dp[i]+1:
        dp[i-1] = dp[i] + 1
        dig = int(stri[i-1])
        digits[dig] = min(digits[dig], dp[i-1])
        i-=2
    else:
        i+=1
length -= 1
dp[length] = min(dp[length],dp[length-1]+1,digits[int(stri[length])]+1)
print(dp[length])