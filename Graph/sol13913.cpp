#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int N, K;
bool visit[100001];
bool tmp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	if ( K < N) {
		cout << N - K << '\n';
		for (int i = N; i >= K ; i--) {
			cout << i << " ";
		}
		return 0;
	}
	queue<pair<int, vector<int>>> q;
	vector<int> v;
	v.push_back(N);
	q.push({N, v});
	memset(visit, false, sizeof(visit));

	while (!q.empty()) {
		tmp = false;
		int time = q.size();
		for (int i = 0 ;i < time; i++) {
			int cur = q.front().first;
			vector<int> course = q.front().second;
			q.pop();

			if (cur == K) {
				cout << course.size() - 1 << '\n';
				for (int i = 0; i < course.size(); i++) {
					cout << course[i] << " ";
				}
				return 0;
			}

			visit[cur] = true;

			if (cur + 1 <= 100000 && !visit[cur + 1]) {
				course.push_back(cur + 1);
				q.push({cur + 1, course});
				tmp = true;
				course.pop_back();
			}

			if (cur - 1 >= 0 && !visit[cur-1]) {
				course.push_back(cur - 1);
				q.push({cur - 1, course});
				tmp = true;
				course.pop_back();
			}

			if (cur * 2 <= 100000 && !visit[cur * 2]) {
				course.push_back(cur * 2);

				q.push({cur*2, course});
				tmp = true;
				course.pop_back();
			}
		}
	}
}