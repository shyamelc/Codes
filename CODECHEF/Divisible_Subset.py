#!/usr/bin/env python3
#http://www.codechef.com/LTIME12/problems/DIVSUBS
test = int(input())
for _ in range(test):
    n = int(input())
    stri = input()
    numbers = [int(x) for x in stri.split()]
    remainders = {0:0}

    if numbers[0]%n == 0:
        print('1')
        print('1')
    else:
        for i in range(1,n):
            if numbers[i]%n==0 :
                print('1')
                print(i+1)
                break
            numbers[i] += numbers[i-1]
            rem = numbers[i]%n
            if rem in remainders:
                j = remainders[rem]
                if j!=0 :
                    j += 1
                print(i-j+1)
                for x in range(j+1,i+2):
                    print(x,end=' ')
                print()
                break
            else:
                remainders[rem] = i
