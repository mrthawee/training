#include <iostream>

using namespace std;

inline int cmp(const void *a, const void *b) {
	int aa = *(int *)a;
	int bb = *(int *)b;
	return (aa < bb) ? -1 : (aa > bb) ? 1 : 0;
}

main() {
	const int size = 5;
	int array[size];
	int n=0;

	while (cin >> array[n++] );
	n--;

	qsort(array, n, sizeof(int), cmp);

	for (int i=0; i<n; i++)
		cout << array[i] << endl;

}
