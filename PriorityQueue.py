import HeapSort as hs
import math
'''
We generally have two operations: insert (to the back) and 
extract (from the front)
'''
def parent(index):
    parent = int((index - 1) / 2)
    print(parent)
    return parent


def extract_max(arr):
    size = len(arr)
    if (size < 1):
        print("Error!")
        return
    max_ele = arr[0]
    arr[0], arr[size - 1] = arr[size - 1], arr[0]
    heap_size = size - 1
    hs.max_heapify(arr, heap_size, 0)
    # arr = arr[0:size - 1]
    del arr[size - 1]
    return max_ele


def increase(arr, index, new_element):
    if (new_element <= arr[index]):
        print("New element smaller than original value!")
        return
    arr[index] = new_element
    while (parent(index) >= 0) and (arr[index] > arr[parent(index)]):
        arr[index], arr[parent(index)] = arr[parent(index)], arr[index]
        index = parent(index)



def insert(arr, new_element):
    heap_size = len(arr)
    heap_size += 1
    arr += [new_element - 1]
    increase(arr, heap_size - 1, new_element)


arr = []
insert(arr, 5)
insert(arr, 100)
insert(arr, -16)
insert(arr, 99)
insert(arr, 24)
insert(arr, 6)

print(arr)

increase(arr, 3, 2037)

print(arr)

print(extract_max(arr))
print(extract_max(arr))
print(extract_max(arr))
print(extract_max(arr))
print(extract_max(arr))
print(arr)
