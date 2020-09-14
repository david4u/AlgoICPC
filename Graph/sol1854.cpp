#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 987654321;
priority_queue<int> dist[1002];
vector<pair<int, int>> adjlst[1002];
int n, m, k;



int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		adjlst[from].push_back({to, cost});
	}
	priority_queue<pair<int, int>> pq;
	pq.push({0, 1});
	dist[1].push(0);
	while(!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		for (int i= 0 ;i < adjlst[here].size(); i++) {
			int there = adjlst[here][i].first;
			int nextDist = adjlst[here][i].second + cost;
			if (dist[there].size() < k) {
				dist[there].push(nextDist);
				pq.push({-nextDist, there});
			}
			else if (nextDist < dist[there].top() ) {
				dist[there].push(nextDist);
				dist[there].pop();
				pq.push({-nextDist, there});
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dist[i].size() == k) {
			cout << dist[i].top() << '\n';
		}
		else {
			cout << -1 << '\n';
		}
	}
}