#include <stdio.h>
#include "util.h"

void selection_sort(int a[], int n) {
  int min_index;

  int i, j;

  for (i=0; i<n; i++) {
    min_index = i;
    for (j=i+1; j<n; j++) {
      if (a[min_index] > a[j]) {
        min_index =j;
      }
    }
    if (min_index != i) {
      swap_int(&a[min_index], &a[i]);
    }
    print_array("step", a, n);
  }
}

void main() {
  int d[] = { 100, 3, 7, 5, 6, 99 };
  int n = 6;

  print_array("input", d, n);
  selection_sort(d, n);
  print_array("output", d, n);
}

