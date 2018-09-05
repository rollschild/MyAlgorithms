#include <stdio.h>

void Swap(int* lhs, int* rhs) {
  int tmp = *lhs;
  *lhs = *rhs;
  *rhs = tmp;
}

void SelectionSort(int arr[], int size) {
  // if (sizeof(arr) == 0) return;
  for (int i = 0; i < size - 1; ++i) {
    int min_index = i;
    for (int j = i + 1; j < size; ++j) {
      if (arr[min_index] > arr[j]) {
        min_index = j;
      }
    }
    Swap(&arr[i], &arr[min_index]);
  }
}

int main() {
  int arr[] = {100, -23, 77, 9, 1024, 22, 22, 9};
  int size = sizeof(arr) / sizeof(arr[0]);
  SelectionSort(arr, size);
  for (int k = 0; k < size; ++k) {
    printf("%d ", arr[k]);
  }
  printf("\n");
  return 0;
}
