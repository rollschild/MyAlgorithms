def merge(arr, p, q, r):
    lhs_len = q - p + 1
    rhs_len = r - q
    
    arr_left = arr[p:(q+1)]
    arr_right = arr[q+1:r+1]

    # print(arr_left)
    # print(arr_right)

    i = 0
    j = 0
    k = p

    while (i < lhs_len) and (j < rhs_len):
        if (arr_left[i] > arr_right[j]):
            arr[k] = arr_right[j]
            j += 1
            k += 1
        else:
            arr[k] = arr_left[i]
            k += 1
            i += 1

    # check elements remained
    while (i < lhs_len) and (k <= r):
        arr[k] = arr_left[i]
        i += 1
        k += 1

    while (j < rhs_len) and (k <= r):
        arr[k] = arr_right[j]
        j += 1
        k += 1

def merge_sort(arr, p, r):
    if p < r:
        q = (int)((p + r) / 2)
        merge_sort(arr, p, q)
        merge_sort(arr, q + 1, r)
        merge(arr, p, q, r)

arr = [2037, -100, 999, 12, 0, 66, 999, 55, 1024, -77]
print("Pre-MergeSort: \n", arr)
size = len(arr)
merge_sort(arr, 0, size - 1)
print("Post_MergeSort: \n", arr)
