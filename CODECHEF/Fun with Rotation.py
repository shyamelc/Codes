#http://www.codechef.com/SEPT14/problems/ROTATION
#!/usr/bin/env python3
counter = 0
stri = input().split()
n = int(stri[0])
m = int(stri[1])
arr = [int(x) for x in input().split()]
for i in range(m):
    stri = input().split()
    d = int(stri[1])
    if stri[0]=='C':
        #print('check ',d,n,d%n)
        counter += (n - d%n)
        counter %= n
        #print(counter,'printing')
    elif stri[0]=='A':
        counter += (d%n)
        counter %= n
        #print(counter,'printing')
    else:
        index = d - counter
        if index <= 0:
            index += n
        elif index > n:
            index %= n
        print(arr[index-1])
    