#include <iostream>
#include <queue>

using namespace std;

bool v[100001] = {false, };
queue<int> q;
bool tmp;
int N, K;
int cnt = 0;
int ans = 0;
int course = 1;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> N >> K;
	q.push(N);

	//BFS
	while(!q.empty()) {
		cnt = 0;
		tmp = false;
		for (int i = 0 ; i < course; i++) {
			int cur = q.front();
			q.pop();

			if (cur == K) {
				cout << ans << '\n';
				return 0;
			}
			v[cur] = true;

			if ( cur + 1 <= 100000 && !v[cur+1]) {
				q.push(cur + 1);
				tmp = true;
				cnt++;
			}
			if (cur - 1 >= 0 && !v[cur-1]) {
				q.push(cur - 1);
				tmp = true;
				cnt++;
			}
			if (cur * 2 <= 100000 && !v[cur*2]) {
				q.push(cur*2);
				tmp = true;
				cnt++;
			}
		}
		course = cnt;
		if (tmp) {
			ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}