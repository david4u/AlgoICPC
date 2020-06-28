#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int K, V, E;
vector<int> adjlist[20001];
int visit[20001];

void doBFS(int startpoint) {
	queue<int> q;
	int cur;
	q.push(startpoint);
	visit[startpoint] = 1;
	int color = 2;
	while(!q.empty()) {
		cur = q.front();
		color = 3 - visit[cur];
		q.pop();
		for (int i = 0; i < adjlist[cur].size(); i++) {
			int next = adjlist[cur][i];
			if( visit[next] == 0) {
				visit[next] = color;
				q.push(next);
			}
		}
		color = 3 - color;
	}
}

bool checkBi() {
	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < adjlist[i].size(); j++){
			if (visit[i] == visit[adjlist[i][j]]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> V >> E;
		int from, to;
		for (int j = 0; j < E; j++) {
			cin >> from >> to;
			adjlist[from].push_back(to);
			adjlist[to].push_back(from);
		}
		for (int j = 1; j <= V; j++) {
			if (!visit[j]) {
				doBFS(j);
			}
		}
		if(checkBi()) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
		for (int j = 0; j <= V; j++) {
			adjlist[j].clear();
			visit[j] = 0;
		}
	}
}