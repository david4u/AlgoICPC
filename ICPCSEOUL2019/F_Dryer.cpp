#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k;
int wet[61];

vector<pair<int, int>> dr1;
vector<pair<int, int>> dr2;
vector<pair<int, int>> dr3;

int min(int x, int y) {
	return x < y ? x : y;
}
int max(int x, int y) {
	return x > y ? x : y;
}


int main() {
	cin >> n >> k;
	for (int i = 0;i <= 60; i++) {
		wet[i] = -1;
	}
	int minimum = 987654321;
	for (int i = 1;i <= n; i++) {
		int temp, cur_wet;
		cin >> temp >> cur_wet;
		if (wet[temp-40] < cur_wet) {
			wet[temp-40] = cur_wet;
		}
		minimum = min(minimum, temp - 40);
	}

	for (int i = 0; i <= 60; i++) {
		if (wet[i] != -1) {
			dr1.push_back({30 + (i - minimum) * wet[i], i});
		}
	}
	if (k == 1) {
		int ansewr = 987654321;
		for (int i = 0 ;i < dr1.size(); i++) {
			answer = min(answer)

		}
		cout << dr1.top().first << '\n';
		return 0;
	}
	if (k == 2) {
		int answer = dr1.top().first;
		for (int t = 1; t <= 60; t++) {
			priority_queue<pair<int, int>> taskpq1;
			for (int i= 1;i <= dr1.size(); i++) {
				taskpq1.push(dr1[i-1]);
			}
			if (dr1.top().second >= t) {
				bool more = true;
				while (more) {
					int curTemp = dr1.top().second;
					if (curTemp < t) {
						more = false;
						continue;
					}
					dr1.pop();

					dr2.push({30 + (curTemp - t) * wet[curTemp], curTemp});
					if (dr1.empty()) {
						more = false;
					}
				}
			answer = min(answer, dr1.top().first + dr2.top().first);
			}

		}

		cout << answer << '\n';
		return 0;
	}

	if (k == 3) {

	}

}