#include <iostream>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int N, M;
int m[101][101];
int dist[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int min(int x, int y) {
	return x < y ? x : y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;
	string buff;
	deque<pair<int, int>> q;
	for (int i = 1; i<= N; i++) {
		cin >> buff;
		for (int j = 1; j <= M ;j++) {
			m[i][j] = buff[j-1] - '0';
		}
	}
	int answer = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j= 0 ; j <= 100; j++) {
			dist[i][j] = 300;
		}
	}

	dist[1][1] = 0;

	q.push_front({1, 1});

	while (!q.empty()) {
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop_front();

		if (cr == N && cc == M) {
			break;
		}

		for (int i = 0 ;i < 4; i++) {
			int nr = cr + dy[i];
			int nc = cc + dx[i];
			if ( 1 <= nr && nr <= N && 1 <= nc && nc <= M) {
				if (dist[nr][nc] == 300) {
					if (m[nr][nc] == 1) {
						dist[nr][nc] = dist[cr][cc] + 1;
						q.push_back({nr, nc});
					}
					if (m[nr][nc] == 0) {
						dist[nr][nc] = dist[cr][cc];
						q.push_front({nr, nc});
					}
				}
			}
		}
	}
	answer = dist[N][M];
	cout << answer << '\n';
}