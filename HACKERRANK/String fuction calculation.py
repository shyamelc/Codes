#!/usr/bin/env python3
#https://www.hackerrank.com/contests/w7/challenges/string-function-calculation
stri = input()
mapp = {}
length = len(stri)
maxi = 0
for i in range(length):
    for j in range(i,length):
        temp = str(stri[i:j+1])
        if temp not in map:
            mapp[temp] = 1
        else:
            mapp[temp] += 1
            
        x = (j-i+1)*(map[temp])
        maxi = max(maxi,x)
print(maxi)
    
