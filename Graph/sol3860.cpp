#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 987654321;
pair<pair<int, int>, int> hole[30][30];
bool grave[30][30];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int W, H, G, E;
int upper[30][30];


int main() {
	while (true) {

		// 초기화 단계
		memset(grave, false, sizeof(grave));
		bool updated;
		bool negativeCycle = false;
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 30; j++) {
				upper[i][j] = INF;
			}
		}
		upper[0][0] = 0;
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 30; j++) {
				hole[i][j] = {{-1, -1}, 0};
			}
		}
		
		// 입력 받기 입력이 0 0 이면 바로 return.
		cin >> W >> H;
		if (W == 0 && H == 0) {
			return 0;
		}
		cin >> G;
		for (int i = 0; i < G; i++) {
			int x, y;
			cin >> x >> y;
			grave[x][y] = true;
		}
		cin >> E;
		for (int i = 0; i < E; i++) {
			int a, b, c, d, e;
			cin >> a >> b >> c >> d >> e;
			hole[a][b] = { {c, d}, e};
		}

		// Bellman-Ford 알고리즘
		for (int iter = 0; iter <= W*H; iter++) {
			updated = false;
			for (int i = 0; i < W; i++) {
				for (int j = 0; j < H; j++) {
					// hole이 존재하지 않는 노드일 경우
					if (hole[i][j].first.first == -1) {
						for (int ddx = 0; ddx < 4; ddx++) {
							int nx = i + dx[ddx];
							int ny = j + dy[ddx];
							if (nx < 0 || ny < 0 || nx >= W || ny >= H || grave[nx][ny]) {
									continue;
							}
							if (upper[nx][ny] > upper[i][j] + 1) {
								upper[nx][ny] = upper[i][j] + 1;
								updated = true;
							}
						}
					}
					// hole 이 존재하는 노드일 경우
					else {
						for (int ddx = 0; ddx < 4; ddx++) {
							int nx = i + dx[ddx];
							int ny = j + dy[ddx];
							if (nx < 0 || ny < 0 || nx >= W || ny >= H || grave[nx][ny]) {
								continue;
							}
							if (upper[nx][ny] > upper[i][j] + 1) {
								upper[nx][ny] = upper[i][j] + 1;
								updated = true;
							}
						}
						int nx = hole[i][j].first.first;
						int ny = hole[i][j].first.second;
						int ncost = hole[i][j].second;
						if (upper[nx][ny] > upper[i][j] + ncost) {
							upper[nx][ny] = upper[i][j] + ncost;
							updated = true;
						}
					}
				}
			}
			if (!updated) break;
		}
		if (updated) {
			negativeCycle = true;
		}

		int answer = upper[W-1][H-1];

		// 틀리는 이유는 0 cycle을 찾지 못하기 때문임. 0 cycle을 어떻게 찾을 지 고민

		if (negativeCycle) {
			cout << "Never\n";
		}
		else if (answer > 981234567) {
			cout << "Impossible\n";
		}
		else {
			cout << answer << '\n';
		}
	}
}