#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K;
	int count;
	int index;
	vector<int> v;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}

	index = K - 1;
	cout << "<";
	while (v.size() > 1) {
		cout << v[index] << ", ";
		v.erase(v.begin() + index);
		index += K - 1;
		index = index % v.size();
	}
	cout << v[0] << ">\n";
}