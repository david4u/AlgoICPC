#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 987654321;
int N, M; // N은 장소의 수, M은 도로의 수 장소는 0 ~ N-1;
vector<pair<int, int>> trace[501];
vector<pair<int, int>> adjlst[501];
bool visit[501][501];

vector<int> dijkstra(int src) {
	vector<int> dist(N, INF);
	dist[src] = 0;
	priority_queue<pair<int ,int>> pq;
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

			if (adjlst[here][i].second == -1) {
				continue;
			}
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push({-nextDist, there});
				trace[there].clear();
				trace[there].push_back({here, nextDist});
			}
			else if (dist[there] == nextDist) {
				trace[there].push_back({here, nextDist});
			}
		}
	}
	return dist;
}

void DelEdges(int end) {
	queue<int> q;
	q.push(end);
	while(!q.empty()) {
		int here = q.front();
		q.pop();

		for (int i = 0; i < trace[here].size(); i++) {
			int there = trace[here][i].first;
			if (visit[here][there]) {
				continue;
			}
			for (int i = 0; i < adjlst[there].size(); i++) {
				if (adjlst[there][i].first == here) {
					adjlst[there][i].second = -1;
				}
			}
			q.push(there);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	while (N != 0 && M != 0) {
		memset(visit, false, sizeof(visit));
		memset(trace, 0, sizeof(trace));
		for (int i = 0; i < 501; i++) {
			adjlst[i].clear();
		}
		int S, D;
		cin >> S >> D;
		for (int i = 0 ;i < M; i++) {
			int from, to, cost;
			cin >> from >> to >> cost;
			adjlst[from].push_back({to, cost});
		}
		dijkstra(S);
		DelEdges(D);
		vector<int> answer = dijkstra(S);

		if (answer[D] == INF) {
			cout << -1 << '\n';
			
		}else {
			cout << answer[D] << '\n';
		}
		cin >> N >> M;		
	}
}
