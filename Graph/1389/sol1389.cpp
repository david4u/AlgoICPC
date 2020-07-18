#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
vector<int> adjlist[101];
int visitN[101];
int user[101];

int main() {
	cin >> N >> M;
	for (int i = 1;i <= M; i++) {
		int from, to;
		cin >> from >> to;
		adjlist[from].push_back(to);
		adjlist[to].push_back(from);
	}
	for (int i = 1; i<= N; i++) {
		queue<int> q;
		q.push(i);
		int cnt = 0;
		memset(visitN, -1, sizeof(visitN));
		visitN[i] = 0;
		int sum = 0;
		while(!q.empty()) {
			int cur = q.front();
			q.pop();
			cnt++;
			vector<int> cv = adjlist[cur];
			for (int j = 0; j < cv.size(); j++) {
				if (visitN[cv[j]] == -1) {
					visitN[cv[j]] = cnt;
					sum += cnt;
					q.push(cv[j]);
				}
			}
		}
		user[i] = sum;
	}
	int answer = 1;
	for (int i = 1; i <= N; i++) {
		if (user[answer] > user[i]) {
			answer = i;
		}
	}
	cout << answer << '\n';
}
