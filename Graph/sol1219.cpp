#include <iostream>
#include <vector>

using namespace std;

const long long INF = 9087654321987654321;
int N, S, D, M;
vector<pair<int, int>> adj[101];
int coin[101];
bool visit[101];
long long dist[101];

void DFS(int here) {
	visit[here] = true;
	for (int i = 0; i < adj[here].size(); i++) {
		if (visit[adj[here][i].first] == false) {
			DFS(adj[here][i].first);
		}
	}
}



int main() {
	cin >> N >> S >> D >> M;
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		adj[from].push_back({to, -1*cost});
	}
	for (int i = 0; i< N; i++) {
		dist[i] = -INF;
	}
	for (int i = 0;i < N; i++) {
		cin >> coin[i];
	}

	DFS(S);
	if (visit[D] == false) {
		cout << "gg\n";
		return 0;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			adj[i][j].second += coin[adj[i][j].first];
		}
	}

	dist[S] = coin[S];
	for (int i = 1; i <= 2*N; i++) {
		for (int j = 0; j < N; j++) {
			for (auto &x : adj[j]) {
				int next = x.first;
				long long cost = x.second;
				if(dist[j] == INF) dist[next] = INF;
				else if (dist[j] != -INF && dist[next] < dist[j] + cost) {
					dist[next] = dist[j] + cost;
					if (i >= N) dist[next] = INF;
				}
			}
		}
	}
	if (dist[D] == INF) cout << "Gee\n";
	else cout << dist[D] << '\n';

}