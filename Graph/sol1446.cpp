#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, D;
vector<pair<int, int>> adjlst[10001];
const int INF = 98764321;

vector<int> dijkstra(int src) {
	vector<int> dist(D + 2, INF);
	dist[src] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({0, src});
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (dist[here] < cost) {
			continue;
		}
		for (int i = 0; i < adjlst[here].size(); i++) {
			int there = adjlst[here][i].first;
			int nextDist = cost + adjlst[here][i].second;
			if (nextDist < dist[there]) {
				dist[there] = nextDist;
				pq.push({-nextDist, there});
			}
		}
	}
	return dist;
}

int main() {
	cin >> n >> D;
	for (int i = 0; i < D; i++) {
		adjlst[i].push_back({i+1, 1});
	}
	for (int i = 0; i < n; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		if (to - from > cost && from <= D && to <= D) {
			adjlst[from].push_back({to, cost});
		}
	}
	vector<int> answer = dijkstra(0);
	if (answer[D] < 0 || answer[D] == INF) {
		cout << -1 << '\n';
		return 0;
	}
	cout << answer[D] << '\n';
}