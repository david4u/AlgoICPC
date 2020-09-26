#include <iostream>
#include <cstring>

using namespace std;

const int INF = 100;
const int MAX = 50;
int n;
int adj[MAX][MAX];
int min(int x , int y ) {
	return x < y ? x : y;
}
int max(int x, int y) {
	return x > y ? x : y;
}

int deserve[MAX];

void floyd() {
	for (int i = 0; i < n ; i++) {
		adj[i][i] = 0;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n ;j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j =0 ;j  < n; j++) {
			adj[i][j] = INF;
		}
	}

	while(true) {
		int from, to;
		cin >> from >> to;
		if (from == -1) {
			break;
		}
		if (adj[from-1][to-1] == INF) {
			adj[from-1][to-1] = 1;
			adj[to-1][from-1] = 1;
		}
	}
	floyd();
	int maximum = 0;
	int answerValue = 50;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				maximum = max(maximum, adj[i][j]);
			}

		}
		deserve[i] = maximum;
		maximum = 0;
		answerValue = min(answerValue, deserve[i]);
	}
	int cnt = 0;
	for (int i = 0 ; i < n; i++) {
		if (deserve[i] == answerValue) {
			cnt++;
		}
	}
	cout << answerValue << " " << cnt << '\n';
	for (int i = 0; i < n; i++) {
		if (deserve[i] == answerValue) {
			cout << i+1 << " ";
		}
	}
}