#!/usr/bin/env python3
def mergeSort(num, start, end):
    if start < end:
        mid = (start+end)//2
        
        mergeSort(num, start, mid)
        mergeSort(num, mid + 1, end)
    
        merge(num, start, mid + 1, end)
        
def merge(array, i, j, end):
    fend = j-1
    k = 0
    new = []
    start = i
    while k < end-start+1 :
        if i > fend:
            for x in range(j,end+1):
                new.append(array[x])
                k += 1
        elif j > end:
            for x in range(i,fend+1):
                new.append(array[x])
                k += 1
        elif array[i] <= array[j]:
            new.append(array[i])
            i += 1
            k += 1
        else:
            new.append(array[j])
            j += 1
            k += 1
    
    array[start:end+1] = new
    

numbers = [int(x) for x in input('Enter numbers in one line space seperated\n').split()]
mergeSort(numbers,0,len(numbers)-1)
print(numbers)
