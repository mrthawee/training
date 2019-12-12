#ifndef __UTIL_H_
#define __UTIL_H_L

void print_array(char *str, int a[], int n) {
  int i;

  printf("%s: ", str);
  for (i=0; i<n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void swap_int(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

#endif
