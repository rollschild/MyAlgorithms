def Merge(arr, p, q, r):
    l_size = q - p + 1
    r_size = r - q

    arr_left = arr[p:q+1]
    arr_right = arr[q+1:r+1]

    i = 0
    j = 0
    k = p

    while (i < l_size) and (j < r_size):
        if (arr_left[i] > arr_right[j]):
            arr[k] = arr_right[j]
            j += 1
        else:
            arr[k] = arr_left[i]
            i += 1
        k += 1

    while(i < l_size):
        arr[k] = arr_left[i]
        i += 1
        k += 1

    while(j < r_size):
        arr[k] = arr_right[j]
        j += 1
        k += 1

def MergeSort(arr, p, r):
    if (p < r):
        q = (int)((p + r) / 2)
        MergeSort(arr, p, q)
        MergeSort(arr, q + 1, r)
        Merge(arr, p, q, r)

arr = [2037, -100, -66, 999, 0, 15, 22, 1024, -66, 10101010, 234, -234]
size = len(arr)
print("Pre-MergeSort: \n", arr)
MergeSort(arr, 0, size - 1)
print("Post-MergeSort: \n", arr)
