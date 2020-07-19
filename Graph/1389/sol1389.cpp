#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int map[101][101];
int N;
int r;
int mini = 9999999;
int ans = -1;

queue<int> q;
int visited[101];

void BFS(int x) {
	visited[x] = 1;
	q.push(x);

	while(!q.empty()) {
		x = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (map[x][i] == 1 && visited[i] == 0) {
				visited[i] = visited[x] + 1;
				q.push(i);
			}
		}
	}
}

int main() {
	cin >> N >> r;
	for (int i = 1;i <= r; i++) {
		int from, to;
		cin >> from >> to;
		map[from][to] = 1;
		map[to][from] = 1;
	}
	for (int i = 1; i <= N; i++) {
		memset(visited, 0, sizeof(visited));
		BFS(i);
		int sum = 0;
		for (int k = 1; k <= N; k++) {
			if (i == k) {
				continue;
			}
			else {
				sum += (visited[k]-1);
			}
		}
		if (sum < mini) {
			mini = sum;
			ans = i;
		}
	}
	cout << ans << '\n';
}