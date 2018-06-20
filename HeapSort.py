# Heap sort
# O(nlogn)

def max_heapify(arr, heap_size, index):
    largest = index
    left = index * 2 + 1
    right = index * 2 + 2

    if (heap_size > left) and (arr[left] > arr[index]):
        largest = left
    if (heap_size > right) and (arr[right] > arr[largest]):
        largest = right

    if (largest != index):
        arr[index], arr[largest] = arr[largest], arr[index]
        max_heapify(arr, heap_size, largest)

def build_heap(arr):
    size = len(arr)
    middle = (int)(size / 2) - 1
    for i in range(middle, -1, -1):
        max_heapify(arr, size, i)

def heap_sort(arr):
    build_heap(arr)
    size = len(arr)
    for j in range(size - 1, 0, -1):
        arr[0], arr[j] = arr[j], arr[0]
        max_heapify(arr, j, 0)


arr = [12, -3, 0, 100, 93, -12222, 5, 23, 15, 14, 13, 12]
print("Pre-HeapSort: ", arr)
heap_sort(arr)
print("Post-HeapSort: ", arr)

