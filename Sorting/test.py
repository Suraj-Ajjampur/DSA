import math

class MergeSort:

    # Merge in range
    def Merge(arr1, arr2):
        i = 0
        j = 0
        
        result = []

        while(i < len(arr1) and j < len(arr2)):

            if arr1[i] < arr2[j]:
                result.append(arr1[i])
                i += 1
            
            else:
                result.append(arr2[j])
                j += 1

        while(i<len(arr1)):
            result.append(arr1[i])
            i += 1

        while(j < len(arr2)):
            result.append(arr2[j])
            j += 1
        
        return result


    def Sort(arr):
        if len(arr) <= 1:
            return arr
        
        mid = len(arr)//2
        left = MergeSort.Sort(arr[:mid])
        right = MergeSort.Sort(arr[mid:])

        return MergeSort.Merge(left,right)


arr = [12, 11, 13, 5, 6, 7]
print('original array ')
print(*arr)
arr = MergeSort.Sort(arr)
print('\nSorted array ')
print(*arr)