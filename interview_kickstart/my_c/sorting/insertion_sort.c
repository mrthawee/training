#include <stdio.h>
#include "util.h"

void insertion_sort(int a[], int n) {
  int i, val, hole;

  for (i=1; i<n; i++) {
    val = a[i];
    hole = i;

    while ((hole > 0) && (val < a[hole-1])) {
      a[hole] = a[hole - 1];
      hole = hole - 1;
    }
    a[hole] = val;

    print_array("step", a, n);
  }
}


void main() {
  int t[] = { 100, 3, 7, 5, 6, 99 };
  int n = 6;

  print_array("input", t, n);
  insertion_sort(t, n);
  print_array("output", t, n);

}
