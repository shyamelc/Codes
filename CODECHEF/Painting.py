#!/usr/bin/env python3
#http://www.codechef.com/COOK47/problems/PNTNG
stri = input().split()
n,m,h = int(stri[0]), int(stri[1]),int(stri[2])
tvalues = []
for i in range(h):
    stri = input().split()
    tvalues.append((int(stri[0]), int(stri[1])))
tvalues.sort(key=lambda x: x[1])

count = 0
answer = 0
total = n*m
i=0
while count < total and i<=h-1:
    if tvalues[i][0] <= total-count:
        answer += tvalues[i][1]*(tvalues[i][0])
        count += tvalues[i][0]
        i += 1
    else:
        remaining = total-count
        count += remaining
        answer += tvalues[i][1]*remaining
        
if count < total:
    print('Impossible')
else:
    print(answer)