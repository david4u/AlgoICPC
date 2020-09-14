#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> xy;

int min(int x, int y) {
	return x < y ? x : y;
}

int distance(pair<int, int> p1, pair<int, int> p2) {
	return (p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second);
}

pair<pair<int, int> , pair<int, int>> closestPair(vector<pair<int, int>> src) {
	if (src.size() == 2) {
		return {src[0], src[1]};
	}
	if (src.size() == 3) {
		int ret = min( min(distance(src[0], src[1]), distance(src[0], src[2])), min(distance(src[1], src[2]), distance(src[0], src[1])));
		if ( ret == distance(src[0], src[1]) ) {
			return { src[0], src[1] };
		}
		if ( ret == distance(src[1], src[2])) {
			return {src[1], src[2]};
		}
		return {src[0], src[2]};
	}

	int mid = src.size() / 2;
	vector<pair<int, int>> L;
	vector<pair<int, int>> R;
	for (int i = 0; i <= mid-1; i++) {
		L.push_back(src[i]);
	}
	for (int i = mid; i < src.size(); i++) {
		R.push_back(src[i]);
	}
	pair<pair<int, int>, pair<int, int>> closeL = closestPair(L);
	pair<pair<int, int>, pair<int, int>> closeR = closestPair(R);
	
	int delta = min(distance(closeL.first, closeL.second), distance(closeR.first, closeR.second));
	mid = src[mid-1].first;
	vector<pair<int, int>> S;
	pair<pair<int, int>, pair<int, int>> tmp;
	for (int i= 0; i < src.size(); i++) {
		if (mid - delta < src[i].first && src[i].first < mid + delta) {
			S.push_back(src[i]);
		}
	}
	if (S.size() <= 1) {
		if (distance(closeL.first, closeL.second) > distance(closeR.first, closeR.second)) {
			return closeR;
		}
		else {
			return closeL;
		}
	}
	tmp = {S[0], S[1]};
	for (int i = 0; i < S.size(); i++) {
		for (int j = i+1; j < i + 7 && j < S.size(); j++) {
			if (distance(tmp.first, tmp.second) > distance(S[i], S[j])) {
				tmp = {S[i], S[j]};
			}
		}
	}
	int hello = min (min(distance(tmp.first, tmp.second), distance(closeL.first, closeL.second)), min(distance(tmp.first, tmp.second), distance(closeR.first, closeR.second)));
	if (hello == distance(tmp.first, tmp.second)) {
		return tmp;
	}
	if (hello == distance(closeL.first, closeL.second)) {
		return closeL;
	}
	if (hello == distance(closeR.first, closeR.second)) {
		return closeR;
	}
	return closeL;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		xy.push_back({x, y});
	}
	sort(xy.begin(), xy.end());
	pair<pair<int, int>, pair<int, int>> answer;
	answer = closestPair(xy);
	cout << distance(answer.first, answer.second) << '\n';
}