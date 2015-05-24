#!/usr/bin/env python3
#http://www.spoj.com/SPC01/problems/KPRD/
test = int(input())
for _ in range(test):
    stri = input().split()
    n , k = int(stri[0]), int(stri[1])
    numbers = [int(x) for x in input().split()]
    numbers.insert(0,0)
    
    mini = n**n
    minseq = []
    for i in range(1,n+1,k):
        seq = numbers[i:i+k]
        inver = 0
        for j in range(1,n+1,k):
            x = 0
            for s in range(j,j+k):
                if numbers[s] != seq[x]:
                    inver += 1
                x += 1
        if inver < mini:
            mini = inver
            minseq = seq
    print(mini,minseq)