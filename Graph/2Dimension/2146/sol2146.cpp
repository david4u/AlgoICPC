#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int map[101][101];
bool visited[101][101];
int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	memset(visited, false, sizeof(visited));
	int count = 0;
	bool more = false;
	queue<pair<int, int>> q;
	for (int i = 1;i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 1) {
				q.push({j, i});
				i = j = N + 1;
				more = true;
			}
		}
	}
	while (more) {
		more = false;
		count++;
		while(!q.empty()) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();
			map[cy][cx] = count;
			visited[cy][cx] = true;
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if ( 1<= nx && nx <= N && 1 <= ny && ny <= N && !visited[ny][nx] && map[ny][nx] == 1) {
					q.push({nx, ny});
				}
			}
		}
		for (int i = 1;i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					q.push({j, i});
					i = j = N + 1;
					more = true;
				}
			}
		}
	}
	// 여기까지 map setting. 섬들을 1번 2번 3번...으로 나눴음.
	// 이제 각 섬들에 대해서 영토 하나씩 넓혀가면서 다른 섬에 얼마나 넓혀야 닿는지 최소값 구하고 그중 최고값 출력.
	// cout << '\n';
	// for (int i = 1; i <= N; i++) {
	// 	for (int j = 1; j <= N; j++) {
	// 		cout << map[i][j];
	// 	}
	// 	cout << '\n';
	// }

}