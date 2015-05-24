#!/usr/bin/env python3
#Randomized Quick Sort
import random
count = 0
def quickSort(num, start, end):
    if start < end:
        global count
        count += end-start
        middle = (end+start)//2
        if num[start] < num[middle] < num[end] or num[end] < num[middle] < num[start]:
            pivot = middle
        elif num[middle] < num[start] < num[end] or num[end] < num[start] < num[middle]:
            pivot = start
        else:
            pivot = end
          
        temp = num[start]
        num[start] = num[pivot]
        num[pivot] = temp
        pivot = start
        i = start
        j = start + 1
        while j <= end:
            if num[j] <= num[pivot]:
                temp = num[i+1]
                num[i+1] = num[j]
                num[j] = temp
                i += 1
            j += 1
            
        temp = num[pivot]
        num[pivot] = num[i]
        num[i] = temp
        quickSort(num, start, i-1)
        quickSort(num, i+1, end)

numbers = []
for i in range(1,10000+1):
    numbers.append(int(input()))
quickSort(numbers, 0, len(numbers)-1)
print(numbers,count)
