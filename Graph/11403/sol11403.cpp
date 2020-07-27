#include <iostream>

using namespace std;

int m[101][101];
int N;

int main() {
	cin >> N;
	for (int i = 1; i<= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> m[i][j];
			if (m[i][j] == 0) {
				m[i][j] = 200;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int r = 1; r <= N; r++) {
			for (int c = 1 ; c <= N; c++) {
				if (m[r][c] > m[r][i] + m[i][c]) {
					m[r][c] = m[r][i] + m[i][c];
				}
			}
		}
	}
	for (int i = 1; i<= N; i++) {
		for (int j = 1; j<= N; j++) {
			if (m[i][j] == 200) {
				cout << 0 << " ";
			} else {
				cout << 1 << " ";
			}
		}
		cout << '\n';
	}

}