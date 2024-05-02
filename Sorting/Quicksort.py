def partition(arr, low, high):
    
    pivot = arr[low]
    i = high +1

    for j in range(high,low):  # Write for loops in python
        if arr[j] >= pivot:
            i-=1 
            (arr[i], arr[j]) = (arr[j], arr[i]) 
        
    (arr[i-1], arr[high]) = (arr[high], arr[i-1]) # Swap array position
    return i-1
            

def QuickSort(arr, low, high):

    if low < high:

        pi = partition(arr, low, high)
        QuickSort(arr, low, pi-1)
        QuickSort(arr, pi+1, high)


if __name__ == "__main__":
    arr = [23, 46, 54, 12, 7, 90, 101, 34]
    print("The original array is ")
    print(*arr)
    n = len(arr)
    QuickSort(arr,0, n-1)
    print("\nThe sorted array is")
    print(*arr)
    
