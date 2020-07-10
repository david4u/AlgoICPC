#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int map[51][51];
bool visit[51][51];
int x, y;
int w, h;
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
bool island;
int answer;
bool more;

class coord {
	public:
		int x;
		int y;
		coord(int cx,int cy) {
			this->x = cx;
			this->y = cy;
		}
};

void BFS(int x, int y) {
	coord cur = coord(x, y);
	queue<coord> q;
	q.push(cur);
	int here;
	here = map[cur.y][cur.x];
	if (map[cur.y][cur.x] == 1) {
		island = true;
	} else {
		island = false;
	}
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (cur.x < 1 || cur.x > w) {
			//do nothing;
		}
		else if (cur.y < 1 || cur.y > h) {
			//do nothing;
		}
		else if (map[cur.y][cur.x] != here) {
			//do nothing;
		}
		else {
			if (!visit[cur.y][cur.x]){
				visit[cur.y][cur.x] = true;
				for (int i = 0; i < 8; i++) {
					q.push(coord(cur.x + dx[i],cur.y + dy[i]));
				}
			}
		}
	}
	if (island) {
		answer++;
	}
}

int main() {
	cin >> w >> h;
	while(w!= 0 && h != 0) {
		memset(map, 0, sizeof(map));
		memset(visit, false, sizeof(visit));
		answer = 0;
		x = y = 1;
		more = true;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> map[i][j];
			}
		}
		while (more) {
			more = false;
			BFS(x, y);
			for (int i = 1; i <= h ; i++) {
				for (int j = 1; j <= w; j++) {
					if (visit[i][j] == false) {
						more = true;
						x = j;
						y = i;
						j = w +1;
						i = h +1;
					}
				}
			}
		}
		cout << answer << '\n';
		cin >> w >> h;
	}
}