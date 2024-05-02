# Python program for merge sort
def merge(arr1, arr2):
    i =0
    j =0
    result=[]
    # Compare both subarrays and then append lesser val to result
    while(i<len(arr1) and j <len(arr2)):
        if arr1[i] < arr2[j]:
            result.append(arr1[i])
            i +=1
        else:
            result.append(arr2[j])
            j += 1
    # copy remaining elements
    while(i<len(arr1)):
        result.append(arr1[i])
        i +=1      
    # copy the elements   
    while(j<len(arr2)):
        result.append(arr2[j])
        j += 1

    return result


def mergeSort(arr):
    if len(arr) <=1:
        return arr
    mid = len(arr)//2 # Floor division //
    left = mergeSort(arr[:mid]) # Slicing in python
    right = mergeSort(arr[mid:]) # Slicing to get 2nd sub array

    return merge(left, right) # Passing the 2 subarrays to merge sort

#Driver Code
if __name__ == '__main__':
    arr = [12,11,13,5,6,7]
    print("Given array is")
    print(*arr)
    arr = mergeSort(arr)
    print("\nSorted array is ")
    print(*arr)
