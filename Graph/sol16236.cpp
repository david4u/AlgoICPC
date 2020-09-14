#include <iostream>
#include <deque>
#include <queue>
#include <vector>

using namespace std;

int N;
int m[101][101];
int shark = 2;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> fish;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(false);
	cout.tie(false);

	cin >> N;
	int r, c;

	for (int i = 1; i<= N; i++) {
		for (int j = 1; j<= N; j++) {
			cin >> m[i][j];
			if (m[i][j] == 9) {
				r = i;
				c = j;
			}
		}
	}
	/*

	BFS 로 상어 움직이면서 먹을 수 있는 거 찾기.
	이 때 상어의 크기 보다 같거나 작은 칸만 지나갈 수 있다.








	*/

	queue<pair<int, int>> q;
	q.push({r, c});
	bool tmp = true;
	while (!q.empty() && tmp) {
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();

		for (int i = 0 ;i < 4; i++) {
			int nr = cr + dx[i];
			int nc = cc = dy[i];
			if (1 <= nr && nr <= N && 1 <= nc && nc <= N) {
				if (m[nr][nc] <= )
			}
		}



	}

}