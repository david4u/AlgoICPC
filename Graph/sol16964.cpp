#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
vector<int> adjlist[100001];
int arr[100001];
bool visit[100001];
int cnt = 1;
bool answer = true;
int orders[100001];

bool cmp(int x, int y) {
	return orders[x] < orders[y];
}

void DFS(int x) {

	if (visit[x] == true) {
		return;
	}

	visit[x] = true;

	if(arr[cnt++] != x) {
		answer = false;
		return;
	}

	for (int i = 0; i < adjlist[x].size(); i++) {
		int y = adjlist[x][i];
		if (visit[y] == false) {
			DFS(y);
		}
	}

	return;
}

int main() {
	cin >> N;
	for (int i = 1; i < N; i++) {
		int from, to;
		cin >> from >> to;
		adjlist[from].push_back(to);
		adjlist[to].push_back(from);
	}
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		orders[arr[i]] = i;
	}
	if (arr[1] != 1) {
		cout << 0 << '\n';
		return 0;
	}
	for (int i = 1; i <= N; i++) {
		sort(adjlist[i].begin(), adjlist[i].end(), cmp);
	}
	memset(visit, false, sizeof(visit));
	DFS(1);
	if (answer) {
		cout << 1 << '\n';
		return 0;
	} else {
		cout << 0 << '\n';
		return 0;
	}
}