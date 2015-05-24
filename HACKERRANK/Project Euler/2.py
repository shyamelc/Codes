#!/usr/bin/env python3
#https://www.hackerrank.com/contests/project-euler/challenges/euler002

def multiply(f):
    a,b,c,d = int(f[0][0]),int(f[0][1]),int(f[1][0]),int(f[1][1])
    f[0][0] = a*3 + b*2
    f[0][1] = a*2 + b
    f[1][0] = c*3 + d*2
    f[1][1] = c*2 + d

fibo = [[1,1],[1,0]]
summ = 0
while True:
    multiply(fibo)
    if fibo[1][1] <= 4000000:
        summ += fibo[1][1]
        print(fibo[1][1],end=' ')
    else:
        print('breaking',fibo[1][1])
        break
print(summ)