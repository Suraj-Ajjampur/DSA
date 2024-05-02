def SelectionSort(array):

    for i in range(0,len(array)):
        min_index = i
        for j in range(i+1,len(array)):
            if array[j] < array[min_index]:
                min_index = j
        
        (array[i], array[min_index]) = (array[min_index], array[i])
    return


arr = [12, 11, 13, 5, 6, 7]
print('original array ')
print(*arr)
SelectionSort(arr)
print('\nSorted array ')
print(*arr)