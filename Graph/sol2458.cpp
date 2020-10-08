#include <iostream>

using namespace std;

int n, m;
int adj[501][501];

int main() {
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			adj[i][j] = 0;
		}
		adj[i][i] = 1;
	}
	for (int i = 0; i < m ; i++) {
		int from , to;
		cin >> from >> to;
		adj[from][to] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (adj[i][k] == 1 && adj[k][j] == 1) {
					adj[i][j] = 1;
				}
			}
		}
	}
	int answer = 0;
	for (int i = 1 ;i <= n; i++) {
		bool correct = true;
		for (int j = 1; j<= n; j++) {
			if (i == j) continue;

			if (adj[i][j] == 0 && adj[j][i] == 0) {
				correct = false;
			}
		}
		if (correct) {
			answer++;
		}
	}
	cout << answer << '\n';

}