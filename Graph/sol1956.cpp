#include <iostream>

using namespace std;

const int INF = 987654321;
const int maxN = 401;
int n, m;
int adj[maxN][maxN];

int min(int x, int y) {
	return x < y ? x : y;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j =1; j <= n; j++) {
			if (i == j) {
				adj[i][j] = 0;
			}
			else {
				adj[i][j] = INF;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int f, t, c;
		cin >> f >> t >> c;
		adj[f][t] = c;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n ;j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
	int dist = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (adj[i][j] != INF && adj[j][i] != INF && i != j) {
				dist = min(dist, adj[i][j] + adj[j][i]);
			}
		}
	}
	if (dist == INF) {
		cout << -1 << '\n';
		return 0;
	}
	cout << dist << '\n';
}