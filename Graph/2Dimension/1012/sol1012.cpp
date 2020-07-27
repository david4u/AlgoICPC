#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
bool map[51][51];
bool visited[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt = 0;

void BFS(int r, int c) {
	queue<pair<int, int>> q;
	q.push({r, c});
	visited[r][c] = true;
	while(!q.empty()) {
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cr + dx[i];
			int nc = cc + dy[i];
			if ( 1 <= nr && nr <= N && 1 <= nc && nc <= M) {
				if (map[nr][nc] == true && visited[nr][nc] == false) {
					visited[nr][nc] = true;
					q.push({nr, nc});
				}
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> M >> N;
		int number;
		cin >> number;
		memset(map, false, sizeof(map));
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= number; i++) {
			int x, y;
			cin >> x >> y;
			map[y+1][x+1] = true;
		}
		bool more = true;
		while (more) {
			more = false;
			for (int i = 1; i<= N; i++) {
				for (int j = 1 ; j <= M; j++) {
					if (map[i][j] == true && visited[i][j] == false) {
						cnt++;
						BFS(i, j);
						more = true;
						i = N+1;
						j = M+1;
					}
				}
			}
		}
		cout << cnt << '\n';
		cnt = 0;
	}
}