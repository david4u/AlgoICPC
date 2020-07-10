#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int map[101][101];
int cost[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int min(int a, int b) {
	return a > b ? b : a;
}
bool visit[101][101];

int N, M;

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string buffer;
		cin >> buffer;
		for (int j = 1; j <= M; j++) {
			map[i][j] = buffer[j-1] - 48;
		}
	}
	memset(cost, 0, sizeof(cost));
	memset(visit, false, sizeof(visit));
	cost[1][1] = 1;
	queue<pair<int, int>> q;
	q.push({1, 1});
	int count = 0;
	while(!q.empty()) {
		int tmp = q.size();
		count++;
		for (int i = 0 ; i < tmp; i++) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nx = cx + dx[j];
				int ny = cy + dy[j];
				if (1 <= nx && nx <= M && 1<= ny && ny <= N && map[ny][nx] == 1 && !visit[ny][nx]) {
					q.push({nx, ny});
					visit[ny][nx] = true;
					cost[ny][nx] = count;
				}
			}
		}
	}
	if (cost[N-1][M] == 0) {
		cout << cost[N][M-1] + 2 <<'\n';
		return 0;
	}	
	if (cost[N][M-1] == 0) {
		cout << cost[N-1][M] + 2 << '\n';
		return 0;
	}
	cout << min(cost[N-1][M] + 2, cost[N][M-1] + 2) << '\n';
}