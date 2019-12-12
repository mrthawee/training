#include <iostream>
#include <vector>

using namespace std;

main() {
	vector< vector<int> > v2d_array(3, vector<int>(2,-1)); // init to -1
//	vector< vector<int> > v2d_array(3, vector<int>(2));

	v2d_array[0][0] = 0;
	v2d_array[0][1] = 1;
	v2d_array[1][0] = 10;
	v2d_array[1][1] = 11;
	v2d_array[2][0] = 20;
	v2d_array[2][1] = 21;

	cout << "Loop by index:" << endl;

	for (int i=0; i<3; i++) {
		for (int j=0; j<2; j++) {
			cout << v2d_array[i][j] << " ";
		}
		cout << endl;
	}
}
