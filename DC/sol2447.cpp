#include <iostream>
#include <cstring>

using namespace std;

bool map[6562][6562];
int N;

void solve(int r, int c, int size) {
	if (size == 1) {
		map[r][c] = true;
		return;
	}
	size /= 3;
	solve(r, c, size);
	solve(r, c+size, size);
	solve(r, c+size*2, size);
	solve(r+size, c, size);
	solve(r+size, c+size*2, size);
	solve(r+size*2, c, size);
	solve(r+size*2, c+size, size);
	solve(r+size*2, c+size*2, size);
}

int main() {
	cin >> N;
	memset(map, false, sizeof(map));
	solve(1, 1, N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if(map[i][j]) {
				cout << '*';
			}
			else {
				cout << ' ';
			}
		}
		cout << '\n';
	}
}