#include <iostream>
#include <queue>

using namespace std;

int tomato[1001][1001];
int N, M;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	cin >> M >> N;
	int count = 0;
	queue<pair<int, int>> q;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j<= M; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				q.push({j,i});
			}
		}
	}
	while(!q.empty()) {
		count++;
		int tmp = q.size();
		for (int i = 0; i < tmp; i++) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nx = cx + dx[j];
				int ny = cy + dy[j];
				if ( 1 <= nx && nx <= M && 1 <= ny && ny <= N) {
					if (tomato[ny][nx] == 0) {
						tomato[ny][nx] = 1;
						q.push({nx, ny});
					}
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (tomato[i][j] == 0) {
				cout << -1 << '\n';
				return 0;
			}
		}
	}
	cout << --count << '\n';
}