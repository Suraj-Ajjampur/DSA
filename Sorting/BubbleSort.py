
def BubbleSort(arr):

    #Outer loop to keep track of the passes
    for i in range(0,len(arr) -1):
        swapped = False 
        for j in range(0, len(arr) - i - 1): # Only till n-i-1 to prevent swapping the already assigned elements
            if arr[j] > arr[j+1]:
                (arr[j], arr[j+1]) = (arr[j+1], arr[j])
                swapped = True
        # Break the loop if no swaps
        if swapped == False:
            break
    return

arr = [12, 11, 13, 5, 6, 7]
print("Original array is \n")
print(*arr)
print('\nSorted array is\n')
BubbleSort(arr)
print(*arr)