#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
pair<int, int> time[100001];

bool cmpfunc(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	return p1.second < p2.second;
}

int main() {
	cin >> N;
	int count = 0;
	for (int i = 1; i <= N; i++) {
		int st, ft;
		cin >> st >> ft;
		time[i] = make_pair(st, ft);
	}
	int lastfinish = 0;
	sort(time + 1, time + N+1, cmpfunc);
	for (int i = 1;i <= N; i++) {
		int st = time[i].first;
		int ft = time[i].second;
		if (st >= lastfinish) {
			count++;
			lastfinish = ft;
		}
	}
	cout << count << '\n';
}