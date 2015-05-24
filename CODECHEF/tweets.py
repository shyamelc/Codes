#!/usr/bin/env python3
#http://www.codechef.com/problems/TWTCLOSE

stri = input().split()
n = int(stri[0])
k = int(stri[1])

data = set()

for i in range(k):
    oper = input().split(' ')
    if oper[0]=='CLOSEALL':
        data.clear()
        print ('0')
    else:
        tweet = int(oper[1])
        if tweet in data :
            data.remove(tweet)
            print(len(data))
        else:
            data.add(tweet)
            print(len(data))