#include <iostream>

using namespace std;

int N;

char stars[][6] = {
	"  *  ",
	" * * ",
	"*****"
};

char map[3500][6500];

void solve(int r, int c, int l) {
	if (l == 1) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 5; j++) {
				map[r+i][c+j] = stars[i][j];
			}
		}
		return;
	}
	solve(r, c + 3*l/2, l/2);
	solve(r + 3*l/2, c, l/2);
	solve(r+3*l/2, c+3*l, l/2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	solve(0, 0, N/3);
	for (int i = 0; i < N+1; i ++) {
		for (int j = 0; j < 2*N-1; j++) {
			if (map[i][j] == '*') {
				cout << '*';
			}
			else {
				cout << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}