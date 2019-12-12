#include <iostream>
#include <vector>
#include <string>

using namespace std;

main() {
	vector<string> SS;

	SS.push_back("This number is 10");
	SS.push_back("This number is 20");
	SS.push_back("This number is 30");

	cout << "Loop by index:" << endl;

	for (int i=0; i<SS.size(); i++) {
		cout << SS[i] << endl;
	}

	cout << endl << "Constant Iterator:" << endl;

	vector<string>::const_iterator ci;
	for (ci=SS.begin(); ci!=SS.end(); ci++) {
		cout << *ci << endl;
	}

	cout << endl << "Reverse Iterator:" << endl;

	vector<string>::reverse_iterator ri;
	for (ri=SS.rbegin(); ri!=SS.rend(); ++ri) {
		cout << *ri << endl;
	}

	cout << endl << "Sample Output:" << endl;

	cout << SS.size() << endl;
	cout << SS[2] << endl;

	swap(SS[0], SS[2]);
	cout << SS[2] << endl;
}
