def insertion_sort(list_of_int):
    for j in range(1, len(list_of_int)):
        i = j - 1
        key = list_of_int[j]
        while (i >= 0) and list_of_int[i] > key:
            list_of_int[i + 1] = list_of_int[i]
            i -= 1
        list_of_int[i + 1] = key

some_list = [12, -23, 0, 100, 7]
sorted_list = insertion_sort(some_list)
print(some_list)
