#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 987654321;
int V, E;
vector<pair<int, int>> adjlst[801];

int min(int x, int y) {
	return x < y ? x : y;
}

vector<int> dijkstra(int src) {
	vector<int> dist(V + 1, INF);
	dist[src] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({0, src});
	while(!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (dist[here] < cost) {
			continue;
		}
		for (int i = 0; i < adjlst[here].size(); i++) {
			int there = adjlst[here][i].first;
			int nextDist = adjlst[here][i].second + cost;
			if (nextDist < dist[there]) {
				dist[there] = nextDist;
				pq.push({-nextDist, there});
			}
		}
	}
	return dist;
}

int main() {
	cin >> V >> E;
	for (int i = 1; i <= E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		adjlst[from].push_back({ to, cost });
		adjlst[to].push_back({ from, cost });
	}
	int v1, v2;
	cin >> v1 >> v2;
	vector<int> dist_1 = dijkstra(1);
	vector<int> dist_v1 = dijkstra(v1);
	vector<int> dist_v2 = dijkstra(v2);
	int answer = min(dist_1[v1] + dist_v1[v2] + dist_v2[V], dist_1[v2] + dist_v2[v1] + dist_v1[V]);
	if (answer < 0 || answer >= INF) {
		cout << -1 << '\n';
		return 0;
	}
	cout << answer << '\n';

}