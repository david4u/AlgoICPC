#include <iostream>

using namespace std;

int min(int x, int y) {
	return x > y ? y : x;
}

int main() {
	int N, M;
	cin >> N >> M;
	if (N == 1) {
		cout << 1 << '\n';
		return 0;
	}
	if (N == 2) {
		cout << min(4, (M+1) / 2) << '\n';
		return 0;
	}
	if (M <= 6) {
		cout << min(4, M) << '\n';
		return 0;
	}
	cout << M-2 << '\n';
	
}