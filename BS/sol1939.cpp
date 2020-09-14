#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;

int cost[100001];
vector<pair<int, long long>> adjlist[100001];
bool visited[10001];


bool BFS(int from, int to, long long cost) {
	visited[from] = true;
	int cur;
	queue<int> q;
	q.push(from);
	while(!q.empty()) {
		cur = q.front();
		q.pop();
		for (int i = 0; i < adjlist[cur].size(); i++) {
			if (adjlist[cur][i].second >= cost && !visited[adjlist[cur][i].first]) {
				if (adjlist[cur][i].first == to) {
					return true;
				}
				visited[adjlist[cur][i].first] = true;
				q.push(adjlist[cur][i].first);
			}
		}
	}
	if (visited[to]) {
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= M ;i++) {
		int from, to;
		long long cost;
		cin >> from >> to >> cost;
		adjlist[from].push_back({to, cost});
		adjlist[to].push_back({from, cost});
	}
	int x, y;
	cin >> x >> y;

	long long left = 1;
	long long right = 1000000000;
	long long answer = 0;
	while (left <= right) {
		memset(visited, false, sizeof(visited));
		long long mid = (left + right) / 2;
		if (BFS(x, y, mid)) {
			if (answer < mid) {
				answer = mid;
			}
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	cout << answer << '\n';


}