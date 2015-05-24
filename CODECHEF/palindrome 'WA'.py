#!/usr/bin/env python3
#http://www.codechef.com/problems/PALIN

def work(s):
    ans = ""
    if len(s) == 2:
        if int(s[0]) > int(s[1]):
            ans = s[0]*2
        elif int(s[0]) == int(s[1]):
            ans = str(int(s[0])+1)*2
        else:
            og = int(s)
            for i in range(int(s[0]), int(s[1])+1):
                ans = int(str(i)*2)
                if ans > og:
                    ans = str(ans)
                    break
    elif len(s) == 3:
            if s[0] == s[-1]:
                ans = s[0] + str(int(s[1])+1) + s[0]
            else:
                temp = work(s[0]+s[-1])
                ans = temp[0] + s[1] + temp[-1]
    if s=='9'*2 :
        ans = '101'
    if s=='9'*3:
        ans = '1001'
    return ans

    
test = int(input())
for i in range(test):
    number = input()
    length = len(number)
    
    x = number[:length//2-1]
    answer = str(x)
    
    if length%2==0:
        answer += work(number[length//2-1:length//2+1])
    else:
        answer += work(number[length//2-1:length//2+2])
    answer += x[::-1]
    
    if len(number) == 1:
        answer = str(int(number)+1)
    if number == '9'*len(number):
        answer = '1'+ '0'*(len(number)-1) + '1'
    print (answer)
    