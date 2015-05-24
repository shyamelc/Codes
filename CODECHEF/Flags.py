#!/usr/bin/env python3
#http://www.codechef.com/COOK47/problems/FLAGS
test = int(input())
for _ in range(test):
    n = int(input())
    answer = [0]*5
    nC2 = (n*(n-1))
    nC3 = (n*(n-1)*(n-2))
    nC4 = (n*(n-1)*(n-2)*(n-3))
    #p1
    if n>=2:
        if n==2:
            answer[0]=2
            answer[1] = 2
        else:
            answer[0] = nC2 + nC3
            answer[1] = answer[0]
    if n>=3:
        if n==3:
            answer[2]=answer[3]=answer[4] = 6
        else:
            answer[2] = nC3
            answer[3] = nC3 + nC4
            answer[4] = answer[3]
    print(sum(answer))