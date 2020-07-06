#include <iostream>
#include <cstring>

using namespace std;

int T, N;
int arr[1001];
bool visit[1001];
int answer = 0;
bool more;

void BFS(int x) {
    int cur = x;
    int next = arr[x];
    if (visit[next] != true) {
        visit[next] = true;
        BFS(next);
    } else {
        answer++;
    }
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        memset(arr, 0, sizeof(arr));
        memset(visit, false, sizeof(visit));
        answer = 0;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }
        more = true;
        int key;
        while(more) {
            more = false;
            for (int i = 1; i<= N; i++) {
                if (visit[i] == false) {
                    key = i;
                    more = true;
                    i = N;
                }
            }
            BFS(key);
        }
        cout << --answer << '\n';

    }
    return 0;
}