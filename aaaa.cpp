#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> ss;

	ss.push_back(1);
	ss.push_back(3);
	ss.push_back(4);
	ss.push_back(10);
	ss.push_back(13);
	ss.push_back(14);
	vector<int>::iterator myi;
	for (int i = 0 ;i < 5; i++) {
		cout << ss[i] << " ";
	}
	cout << '\n';
	myi = lower_bound(ss.begin(), ss.end(), 4);
	if (myi == ss.end()) {
		return 0;
	}
	cout << *myi;
}