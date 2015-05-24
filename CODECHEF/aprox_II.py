#!/usr/bin/env python3
#http://www.codechef.com/LTIME12/problems/APPROX2/
test = int(input())
for _ in range(test):
    stri = input().split()
    n = int(stri[0])
    k = int(stri[1])
    numbers = []
    stri = input().split()
    for i in range(n):
        numbers.append(int(stri[i]))
    numbers.sort()
    minimum = 2*1000000009
    count = 0
    for i in range(n):
        for j in range(i+1,n):
            temp = abs(numbers[i]+numbers[j]-k)
            if(temp < minimum):
                minimum = temp
                count = 1
            elif temp == minimum:
                count += 1
            elif temp > minimum:
                break
    
    print(minimum,count)