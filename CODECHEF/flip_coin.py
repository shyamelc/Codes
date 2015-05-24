#!/usr/bin/env python3
#http://www.codechef.com/problems/FLIPCOIN
stri = input().split()
n,q = int(stri[0]), int(stri[1])
data = set()
for i in range(q):
    stri = input().split()
    oper, A, B = int(stri[0]), int(stri[1]), int(stri[2])
    if(oper==0):
        for x in range(A,B+1):
            if x in data:
                data.remove(x)
            else:
                data.add(x)
    else:
        count = 0
        for x in range(A,B+1):
            if x in data:
                count += 1
        print(count)