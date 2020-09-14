#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<pair<int, int>> pq;
	pq.push_back({2, 1});
	pq.push_back({3,2 });
	pq.push_back({7, 24});
	pq.push_back({1,23 });
	pq.push_back({5, 1});
	pq.push_back({2, 3});
	pq.push_back({4, 5});
	pq.push_back({5, 2});
	pq.push_back({1, 3});
	pq.push_back({1, 43});
	pq.push_back({8, 43});
	pq.push_back({7, 1});
	pq.push_back({4, 2});
	pq.push_back({4, 3});
	sort(pq.begin(), pq.end());
	for (int i = 0; i < pq.size(); i++) {
		cout << pq[i].first << ", " << pq[i].second << '\n';
	}
}