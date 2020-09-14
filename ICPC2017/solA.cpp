#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> line;
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int c1, c2;
	cin >> c1 >> c2;
	c1 = abs(c1 - c2);
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		line.push_back({input, 0});
	}
	for (int i= 0; i < m; i++) {
		int input;
		cin >> input;
		line.push_back({input, 1});
	}
	sort(line.begin(), line.end());
	pair<int, int> answer = {987654321, 0};
	for (int i = 0; i < line.size() - 1; i++) {
		if(line[i].second != line[i+1].second) {
			int tmp = abs(line[i].first - line[i+1].first);
			if (answer.first > tmp) {
				answer = {tmp, 1};
			}
			else if (answer.first == tmp) {
				answer.second++;
			}
		}
	}
	cout << answer.first + c1 << " " << answer.second << '\n';
}