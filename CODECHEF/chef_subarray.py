#!/usr/bin/env python3
#http://www.codechef.com/JUNE14/problems/CHEFZOT

n = int(input())
zeros = [-1]
stri = input().split()

for i in range(n):
    if stri[i]=='0':
        zeros.append(i)
zeros.append(n)
diff = []
for i in range(1,len(zeros)):
    diff.append(zeros[i]-zeros[i-1])


if diff == [1]:
    diff = [2]
if len(zeros)==0:
    print(n)
else:
    print(max(diff)-1)
    