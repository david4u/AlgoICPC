#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

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
		int nowCost = -pq.top().first;
		int here = pq.top().second;
	
		pq.pop();

		if (dist[here] < nowCost) continue;
		
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int nextDist = adj[here][i].second + nowCost;
			if (nextDist < dist[there]) {
				dist[there] = nextDist;
				pq.push({-dist[there], there});
			}
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
	vector<int> answer = dijkstra(start);
	for (int i = 1;i <= V; i++) {
		if (answer[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << answer[i] << '\n';
		}
	}
}