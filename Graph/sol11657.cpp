#include <iostream>
#include <cstring>

using namespace std;

int N, M;

long long dist[501];

const long long INF = 1000000000;

struct edge {
	int from;
	int to;
	int cost;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	edge edges[6001];

	cin >> N >> M;
	
	int cnt = M;

	for (int i = 1; i <= M ;i++) {
		cin >> edges[i].from >> edges[i].to >> edges[i].cost;
	}

	for (int i = 1; i<= N; i++) {
		dist[i] = INF;
	}

	dist[1] = 0;

	for (int i = 1; i <= N-1; i++) {
		for (int j = 1; j <= M; j++) {

			int f, t, c;

			f = edges[j].from;
			t = edges[j].to;
			c = edges[j].cost;

			if (dist[f] == INF) {
				continue;
			}
			if (dist[t] > dist[f] + c) {
				dist[t] = dist[f] + c;
			}
		}
	}

	for (int i = 1; i <= M; i++) {
		int f = edges[i].from;
		int t = edges[i].to;
		int c = edges[i].cost;

		if (dist[f] == INF) {
			continue;
		}
		
		if (dist[t] > dist[f] + c) {
			cout << -1 << '\n';
			return 0;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (dist[i] == INF) {
			cout << -1 << '\n';
		}
		else {
			cout << dist[i] << '\n';
		}
	}
}