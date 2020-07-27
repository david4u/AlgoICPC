#include <iostream>

using namespace std;

const int maxv = 3*3*3*3*3*3*3;
int N;
int m[maxv+1][maxv+1];
int ans[3] = {0,0,0};

void solve(int startr, int startc, int length) {
	int cur = m[startr][startc];
	bool check = true;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (m[startr+i][startc+j] != cur) {
				check = false;
					solve(startr, startc, length/3);
					solve(startr, startc + length/3, length/3);
					solve(startr, startc + length/3*2, length/3);

					solve(startr+length/3, startc, length/3);
					solve(startr+length/3, startc + length/3, length/3);
					solve(startr + length/3, startc + length/3*2, length/3);
					
					solve(startr+ length/3*2, startc, length/3);
					solve(startr+ length/3*2, startc + length/3, length/3);
					solve(startr+ length/3*2, startc + length/3*2, length/3);
				i = 10000;
				j = 10000;
			}
		}
	}
	if (check) {
		ans[cur+1]++;
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> m[i][j];
		}
	}
	solve(1, 1, N);
	cout << ans[0] << '\n';
	cout << ans[1] << '\n';
	cout << ans[2] << '\n';
}