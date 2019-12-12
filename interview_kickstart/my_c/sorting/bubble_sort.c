#include<stdio.h>
#include"util.h"

void bubble_sort_v1(int a[], int n) {
  int i, j; /*, tmp; */

  for (i=0; i<n; i++) {
    for (j=i+1; j<n; j++) {
      if (a[i] > a[j]) {
        swap_int(&a[i], &a[j]);
//        print_array("  inner step", a, n);
      }
    }
    print_array("step", a, n);
  }
}

void bubble_sort_v2(int a[], int n) {
  int i, j;

  for (i=1; i<=n-1; i++) {
    for (j=0; j<=n-2; j++) {
      if (a[j] > a[j+1]) {
        swap_int(&a[j], &a[j+1]);
      }
    }
    print_array("step", a, n);
  }
}

int main() {
  int t[] = { 100, 3, 7, 5, 6, 99 };
  //int t[] = { 2, 7, 4, 1, 5, 3 };
  int n = 6;

  print_array("input", t, n);
  bubble_sort_v1(t, n);
  print_array("output", t, n);

  /*
  int t2[] = { 2, 7, 4, 1, 5, 3 };
  print_array("input", t2, n);
  bubble_sort_v2(t2, n);
  print_array("output", t2, n);
  */
}
