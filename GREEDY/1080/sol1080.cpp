#include <iostream>

using namespace std;

int cnt = 0;
int m[51][51];
int g[51][51];
int N, M;

int main() {
	cin >> N >> M;
	string buff;
	for (int i = 1; i <= N; i++) {
		cin >> buff;
		for (int j =1 ;j <= M; j++) {
			m[i][j] = buff[j-1] - '0';
		}
	}
	for (int i = 1; i <= N; i++) {
		cin >> buff;
		for (int j = 1; j <= M; j++) {
			g[i][j] = buff[j-1] - '0';
		}
	}

	for (int i = 1; i <= N-2; i++) {
		for (int j = 1; j <= M-2; j++) {
			if (m[i][j] != g[i][j]) {
				cnt++;
				for (int dx = 0 ; dx < 3; dx++) {
					for (int dy = 0; dy < 3 ; dy++) {
						m[i+dy][j+dx] = 1 - m[i+dy][j+dx];
					}
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1 ; j <= M; j++) {
			if (m[i][j] != g[i][j]) {
				cout << "-1" << '\n';
				return 0;
			}
		}
	}
	cout << cnt << '\n';
}