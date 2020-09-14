#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;

int V, E, start;
vector<pair<int, int>> adj[20001];

int min(int x, int y) {
	return x < y ? x : y;
}

vector<int> dijkstra(int src) {
	vector<int> dist(V + 1, INF);
	dist[src] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({0, src});
	while (!pq.empty()) {
		int here = pq.top().second;
		int nowCost = -pq.top().first;
		pq.pop();
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			if (dist[there] != INF) {
				continue;
			}
			int nextDist = adj[here][i].second + nowCost;
			nextDist = min(nextDist, dist[there]);
			dist[there] = nextDist;
			pq.push({-nextDist, there});
		}
	}
	return dist;
	
}

int main() {
	cin >> V >> E;
	cin >> start;
	for (int i = 1;i <= E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		adj[from].push_back({to, cost});
	}
	vector<int> answer = dijkstra(1);
	for (int i = 1;i <= V; i++) {
		if (answer[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << answer[i] << '\n';
		}
	}
}