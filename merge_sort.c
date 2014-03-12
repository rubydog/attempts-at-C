#include <stdio.h>


int merge_sort(int array[]);

main() {
  int a1[7] = [1, 4, 8, 6, 3, 5, 9, 7];
  int result[8];
  result = merge_sort(a1);
  printf("%d", result);
}

int merge_sort(int array[]) {
    int left[], right[], result[], floor;
    if sizeof(array) <= 1
      return array;

    floor = sizeof(array)/2;
    for(int i = 0; i < floor; i++)
      left[i] = array[i];
    for(int j = 0; j < floor; j++)
      right[j] = array[j+floor];
    left = merge_sort(left);
    right = merge_sort(right);
    result = merge(left, right);
    return result;
}

