#include <iostream>

using namespace std;

int max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	int f, m, k;
	cin >> f >> m >> k;
	int team = 0;
	while (f >= 2 && m >= 1 && f + m >= 3 + k) {
		f -= 2;
		m--;
		team++;
	}
	cout << team << '\n';
}