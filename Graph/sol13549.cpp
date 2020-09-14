#include <iostream>
#include <deque>

using namespace std;

int N, K;
bool visit[200001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	deque<pair<int, int>> dq;
	dq.push_front({0, N});

	while (!dq.empty()) {
		int cur = dq.front().second;
		int prg = dq.front().first;
		dq.pop_front();

		if (cur == K) {
			cout << prg << '\n';
			return 0;
		}

		if (cur * 2 <= K + 1 && !visit[cur * 2]) {
			visit[cur * 2] = true;
			dq.push_front({prg, cur * 2});
		}
		if ( cur + 1 <= K && !visit[cur + 1]) {
			visit[cur + 1] = true;
			dq.push_back({prg+1, cur + 1});
		}
		if ( cur - 1 >= 0 && !visit[cur - 1]) {
			visit[cur - 1] = true;
			dq.push_back({prg+1, cur - 1});
		}

	}

}