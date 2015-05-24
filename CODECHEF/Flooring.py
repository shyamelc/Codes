#!/usr/bin/env python3
test = int(input())
for i in range(test):
    stri = input().split()
    n = int(stri[0])
    m = int(stri[1])
    nRsix = n**6
    answer = 2*nRsix
    nRsix = nRsix//n
    answer += 12*nRsix
    nRsix = nRsix//n
    answer += 25*nRsix
    nRsix = nRsix//n
    answer += 20*nRsix
    nRsix = nRsix//n
    answer -= 2*nRsix
    nRsix = nRsix//n
    answer -= 2*nRsix
    answer = answer//60
    
    
    temp = 2*(n**6) + 12*(n**5) + 25*(n**4) + 20*(n**3) - 2*(n*n) - 2*n
    temp = temp // 60
    print(temp)
    print(answer)