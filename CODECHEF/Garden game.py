#!/usr/bin/env python3
import fractions

test = int(input())
for i in range(test):
    n = int(input())
    array = [int(x) for x in input().split()]
    array.insert(0,0)
    count = []
    seen = {}
    toSee = 0
    for i in range(1,n+1):
        j = 1
        x = array[i]
        if x not in seen:
            seen[x] = None
            while x != i:
                x = array[x]
                seen[x] = None
                j += 1
            count.append(j)
            toSee += 1

    lcm = 1
    for i in range(toSee):
        lcm = (lcm*count[i])//fractions.gcd(lcm,count[i])
    print(lcm%((10**9) + 7))
    
