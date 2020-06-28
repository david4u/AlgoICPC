#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> vertices(1001);
int N, M, V;

queue<int> q;

bool check[1001];
bool check2[1001];

void doDFS(int v) {
    check[v] = true;
    cout << v << " ";
    for (int i = 0; i < vertices[v].size(); i++) {
        int next;
        next = vertices[v][i];
        if (check[next] == false) {
            doDFS(next);
        }
    }
}

int main() {
    cin >> N >> M >> V;
    for (int i = 1; i <= N; i++) {
        vector<int> edgesBtw;
        vertices[i] = edgesBtw;
    }
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        vertices[from].push_back(to);
        vertices[to].push_back(from);
    }
    for (int i = 1; i <= N; i++) {
        sort(vertices[i].begin(), vertices[i].end());
    }

    doDFS(V);
    cout << "\n";

    check2[V] = true;
    q.push(V);
    while (!q.empty()) {
        int cur = q.front();
        cout << cur << " ";
        q.pop();
        for (int i = 0; i < vertices[cur].size(); i++) {
            int next;
            next = vertices[cur][i];
            if (check2[next] == false) {
                q.push(next);
                check2[next] = true;
            }
        }
    }
    cout << "\n";

    return 0;
}