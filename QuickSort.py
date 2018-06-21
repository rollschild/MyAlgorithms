# QuickSort
# Partition

def quick_sort(arr, p, r):
    if (p < r):
        q = partition(arr, p, r)
        quick_sort(arr, p, q - 1)
        quick_sort(arr, q + 1, r)

def partition(arr, p, r):
    key = arr[r]
    i = p - 1
    for j in range(p, r):
        if (arr[j] < key):
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[r] = arr[r], arr[i + 1]
    return i + 1

arr = [12, 23, -100, 6, 69, 49, 49, 49, 12, 2037, -8]
print(arr)
r = len(arr)
quick_sort(arr, 0, r - 1)
print(arr)
