#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool visit[2001];
vector<int> v[2001];

void DFS(int cur, int cnt) {
	visit[cur] = true;
	if(cnt == 4) {
		cout << 1 << '\n';
		exit(0);
	}

	for (int i = 0 ; i< v[cur].size(); i++) {
		if(!visit[v[cur][i]]) {
			DFS(v[cur][i], cnt + 1);
		}
	}

	visit[cur] = false;
}


int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		int from , to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	for (int i = 0; i < N ; i++) {
		DFS(i, 0);
	}
	cout << 0 << '\n';
	return 0;
}