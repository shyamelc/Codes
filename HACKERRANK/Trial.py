#!/usr/bin/env python3
stri = input()
length = len(stri)
mapp = {}
maxi = 0
for i in range(length):
    char stri[i]
    if char in mapp:
        mapp[char] += 1
    else:
        mapp[char] = 1
    if mapp[char] > maxi:
        maxi = mapp[char]

mapp.clear()

for i in range(length):
    for j in range(i,length,2):
        temp = stri[i:j]
        if temp in mapp:
            mapp[temp] += 1
        else:
            mapp[temp] = 1
        x = (j-i+1)*(mapp[temp])
        if x>maxi:
            maxi = x
print(maxi)

        
    
