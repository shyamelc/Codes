#!/usr/bin/env python3
#http://www.codechef.com/JUNE14/problems/FORGETPW

test = int(input())
for _ in range(test):
    rules = {}
    n = int(input())
    for i in range(n):
        stri = input().split()
        rules[stri[0]] = stri[1]
    ogs = input()
    s = str(ogs)
    
    for j in range(len(ogs)):
        if ogs[j] in rules:
            s = s[:j] + rules[ogs[j]] + ogs[j+1:]
    s = s.strip('0')
    if s[-1] == '.':
        s = s.replace('.','')
    if s=='':
        s = '0'
    print(s)