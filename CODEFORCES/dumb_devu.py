#!/usr/bin/env python3
#http://codeforces.com/contest/439/problem/B
stri = input().split()
n = int(stri[0])
x = int(stri[1])
stri = input().split()
chapters = []
for i in range(n):
    chapters.append(int(stri[i]))
chapters.sort()
answer = 0
for i in range(n):
    answer += chapters[i]*x
    if(x>1):
        x -= 1

print (answer)