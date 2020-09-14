#include <iostream>

using namespace std;

int const INF = 987654321;

int n, m;

int d[101][101];

int min(int x, int y) {
	return x < y ? x : y;
}

int main() {
	cin >> n >> m;

	for (int i = 1; i<= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = INF;
		}
	}

	for (int i = 1;i <= m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		d[from][to] = min (d[from][to], cost);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (d[j][i] != INF && d[i][k] != INF) {
					d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
				}
			}
		}
	}

	for(int i = 1;i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || d[i][j] == INF) {
				cout << 0 << " ";
			} else {
				cout << d[i][j] << " " ;
			}
		}
		cout << '\n';
	}
	return 0;
}