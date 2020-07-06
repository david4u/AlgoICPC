#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[51][51];
bool visit[51][51];
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, -1, 0, 1, -1, 1, -1, 0};
int answer;
bool more;

// coordinate -> (y, x)
void BFS(int y, int x) {
    // do bfs using queue
    queue<int, int> q;
    q.push(pair(y, x));
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
    }

}


int main() {
    int w, h;
    cin >> w >> h;
    int x, y;
    x = y = 1; 
    while( w != 0 && h != 0) {
        answer = 0;
        more = true;
        memset(map, 0, sizeof(map));
        memset(visit, false, sizeof(visit));
        while (more) {
            more = false;
            for (int i = 1; i <= h; i++) {
                for (int j = 1; j <= w; j++) {
                    if (visit[j][i] == false) {
                        x = j;
                        y = i;
                        j = w + 1;
                        i = h + 1;
                        more = true;
                    }
                }
            }
            BFS(y, x);
        }
        cout << answer << '\n';
    }

}