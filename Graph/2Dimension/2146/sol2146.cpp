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

int min(int x, int y) {
	return x > y ? y : x;
}

int BFS(int x) {
    queue<pair<int, int>> q;
    for (int i = 1 ; i<= N; i++) {
        for (int j = 1; j <= N; j++) {
            if(map[i][j] == x) {
                visited[i][j] = true;
                q.push({j, i});
            }
        }
    }
    int result = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();
            
            for (int j = 0 ; j <4; j++) {
                int ny = cy + dy[j];
                int nx = cx + dx[j];
                if ( 1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                    if (map[ny][nx] != 0 && map[ny][nx] != x) {
                        return result;
                    }
                    else if (map[ny][nx] == 0 && !visited[ny][nx]) {
                        visited[ny][nx] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
		result++;
    }
}

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
	queue<pair<int, int>> edge;
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
				if ( 1<= nx && nx <= N && 1 <= ny && ny <= N && !visited[ny][nx] && map[ny][nx] == 0) {
					edge.push({cx, cy});
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
	int answer = 10000;
    for (int i = 1; i <= count; i++) {
        memset(visited, false, sizeof(visited));
        answer = min(answer, BFS(i));
    }
	cout << answer << '\n';
}