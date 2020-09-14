#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N;
int isl[101][101];
bool visit[101][101];
bool edgecheck[101][101];
bool done[101];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int cnt;
queue<pair<int, int>> edges[101];

int min(int x, int y) {
	return x < y ? x : y;
}

int solve() {
	int answer = 2;
	memset(visit, false, sizeof(visit));

	while (true) {
		memset(done, false, sizeof(done));
		
		// i 는 섬 number
		for (int i = 1; i <= cnt; i++) {
		
			int length = edges[i].size();
			
			done[i] = true;
		
			for (int idx = 0; idx < length; idx++) {

				int cr = edges[i].front().first;
				int cc = edges[i].front().second;
				
				visit[cr][cc] = true;
				edges[i].pop();
				
				for (int k = 0; k < 4; k++) {
					int nr = cr + dr[k];
					int nc = cc + dc[k];
				
					if ( 1 <= nr && nr <= N && 1 <= nc && nc <= N) {
						// 다른 섬을 만났을 때
						if (isl[nr][nc] != 0 && isl[nr][nc] != i) {
							if (done[isl[nr][nc]]) {
								cout << answer - 1 << '\n';
								return 0;
							}
							else {
								cout << answer - 2 << '\n';
								return 0;
							}
						}

						// 다른 섬을 만나지 못했을때에는 그냥 확장.
						if (isl[nr][nc] == 0 && !visit[nr][nc]) {
							isl[nr][nc] = i;
							edges[i].push({nr, nc});
						}
					}
				}
			}
		}
		answer += 2;
	}
	return -1;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> isl[i][j];
		}
	}

	cnt = 1;
	bool more = true;
	queue<pair<int, int>> q;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if(isl[i][j] == 1) {
				q.push({i, j});
				i = 200;
				j = 200;
				more = true;
			}
		}
	}
	memset(visit, false, sizeof(visit));
	memset(edgecheck, false, sizeof(edgecheck));

	while (more) {
		more = false;

		while (!q.empty()) {
			int cr = q.front().first;
			int cc = q.front().second;
			q.pop();
			
			isl[cr][cc] = cnt;
			visit[cr][cc] = true;
			bool edge =false;
			for (int d = 0; d < 4; d++) {
				int nr = cr + dr[d];
				int nc = cc + dc[d];
				if (1 <= nr && nr <= N && 1 <= nc && nc <= N) {
					if (!visit[nr][nc] && isl[nr][nc] == 1) {
						q.push({nr, nc});
					}
					if (isl[nr][nc] == 0) {
						edge = true;
					}
				}
			}
			if (edge && !edgecheck[cr][cc]) {
				edges[cnt].push({cr, cc});
				edgecheck[cr][cc] = true;
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (isl[i][j] == 1 && visit[i][j] == false) {
					q.push({i, j});
					more = true;
					cnt++;
					i = 200;
					j = 200;
				}
			}
		}
	}

	// island numbering check

	// for (int i = 1; i<= N; i++) {
	// 	for (int j= 1; j <= N; j++) {
	// 		cout << isl[i][j] << " " ;
	// 	}
	// 	cout << '\n';
	// }


	// edge push check

	// for (int i = 1; i <= cnt; i++) {
	// 	cout << i << '\n';
	// 	for (int j = 0; j < edges[i].size(); j++) {
	// 		cout <<"(" << edges[i][j].first << ", " << edges[i][j].second <<  ") ";
	// 	}
	// 	cout << '\n';
	// }

	solve();

}