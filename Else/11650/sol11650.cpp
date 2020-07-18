#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first == p2.first) {
		return p1.second < p2.second;
	}
	return p1.first < p2.first;
}

int main() {
	int N;
	vector<pair<int, int>> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({x,y});
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < N; i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}
}