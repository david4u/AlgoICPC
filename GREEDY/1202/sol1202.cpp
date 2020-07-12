#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
pair<int, int> jw[300001];
long long answer = 0;
vector<int> bag;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first == p2.first) {
		return p1.first < p2.first;
	}
	return p1.second > p2.second;
}

int findbag(int w) {
	if (bag.size() == 0) {
		return -1;
	}
	int left = 0;
	int right = bag.size() - 1;
	int mid;
	if(bag[left] == w) {
		return left;
	}
	if(bag[right] == w) {
		return right;
	}
	if(bag[right] < w) {
		return -1;
	}
	while(left < right) {
		mid = (left + right) / 2;
		if (bag[mid] == w) {
			return mid;
		}
		else if (bag[mid] > w) {
			right = mid - 1;
		}
		else if (bag[mid] < w) {
			left = mid + 1;
		}
	}
	if (bag[left] > w) {
		return left;
	}
	else if (left + 1 <= bag.size() - 1 && bag[left + 1] > w) {
		return left + 1;
	}
	return -1;
}

int main() {
	cin >> N >> K;
	for (int i = 1;i <= N; i++) {
		int w, c;
		cin >> w >> c;
		jw[i] = make_pair(w, c);
	}
	int w;
	for (int i = 1;i <= K; i++) {
		cin >> w;
		bag.push_back(w);
	}
	sort(jw + 1, jw + N + 1, cmp);
	sort(bag.begin(), bag.end());
	for (int i = 1; i<= N; i++) {
		int value = jw[i].second;
		int weight = jw[i].first;
		int idx = findbag(weight);
		if (idx != -1) {
			answer += value;
			vector<int>::iterator iter = bag.begin() + idx;
			bag.erase(iter);
		}
	}
	cout << answer << '\n';
}