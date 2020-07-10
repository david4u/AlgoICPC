#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int map[26][26];

int main() {
	cin >> N;
	string buff;
	for (int i = 1; i <= N; i++) {
		cin >> buff;
		for (int j = 0;j < N; j++) {
			map[i][j+1] = buff[j] - 48;
		}
	}
	vector<int> ans;
	queue<pair<int, int>> q;
	int x, y;
	bool more = false;
	for (int i = 1;i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 1) {
				x = j;
				y = i;
				i = j = N + 1;
				more = true;
			}
		}
	}
	while (more) {
		more = false;
		q.push({x, y});
		int house = 1;
		map[y][x] = 0;
		while (!q.empty()) {
			int cx = q.front().first;
			int cy = q.front().second;
			map[cy][cx] = 0;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (1 <= nx && nx <= N && 1 <= ny && ny <= N && map[ny][nx] == 1) {
					q.push({nx, ny});
					map[ny][nx] = 0;
					house++;
				}
			}
		}
		ans.push_back(house);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][j] == 1) {
					x = j;
					y = i;
					i = j = N + 1;
					more = true;
				}
			}
		}
	}

	sort(ans.begin(), ans.end());
	int tmp = ans.size();
	cout << tmp << '\n';
	for (int i = 0; i < tmp; i++) {
		cout << ans[i] << '\n';
	}
}