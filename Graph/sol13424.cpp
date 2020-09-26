#include <iostream>
#include <cstring>

using namespace std;

const int INF = 10000000;
const int maxN = 101;
int n, m;
int T;
int adj[maxN][maxN];
int maxDist[maxN];
int min(int x, int y) {
	return x < y ? x : y;
}
int max(int x, int y) {
	return x > y ? x : y;

}
bool check[maxN];

void floyd() {
	for (int i = 1; i <= n ; i++) {
		adj[i][i] = 0;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n ;j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
}

int main() {
	cin >> T;
	while (T--) {
		memset(check, false, sizeof(check));
		memset(maxDist, -1, sizeof(maxDist));
		for (int i = 0; i < maxN; i++) {
			for (int j = 0; j < maxN; j++) {
				adj[i][j] = INF;
			}
		}

		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int from, to, cost;
			cin >> from >> to >> cost;
			adj[from][to] = min(adj[from][to], cost);
			adj[to][from] = min(adj[to][from], cost);
		}
		int people;
		cin >> people;
		for (int i = 0; i < people; i++) {
			int where;
			cin >> where;
			check[where] = true;
		}
		
		floyd();
		for (int i = 1; i <= n; i++) {
			if (check[i] == true) {
				for (int j = 1; j<= n; j++) {
					maxDist[j] = max(maxDist[j], adj[i][j]);
				}
			}
		}
		int answer;
		int dist = INF;
		for (int i = 1; i <= n; i++) {
			if (dist > maxDist[i]) {
				dist = maxDist[i];
				answer = i;
			}
		}
		cout << answer << '\n';
	}
}