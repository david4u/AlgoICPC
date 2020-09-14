#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int from, to;

long long dist[1001];

vector<pair<int, int>> adjlst[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i<= M; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		adjlst[start].push_back({end, cost});
	}

	for (int i = 0; i <= 1000; i++) {
		dist[i] = 987654321;
	}

	cin >> from >> to;

	priority_queue<pair<int, int>> pq;
	
	pq.push({0, from});

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost) {
			continue;
		}

		for (int i = 0; i < adjlst[cur].size(); i++) {
			int next = adjlst[cur][i].first;
			int tmp = cost + adjlst[cur][i].second;

			if (dist[next] > tmp) {
				dist[next] = tmp;
				pq.push({-tmp, next});
			}
		}
	}

	cout << dist[to] << '\n';
	
}