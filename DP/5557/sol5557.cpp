#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[101];
int goal;
long long answer = 0;
vector<long long> v;

void find(vector<long long> v1, int idx) {
	if (idx == N-1) {
		int size = v1.size();
		for (int i = 0 ; i < size; i++) {
			if (v1[i] - arr[idx] == goal) {
				answer++;
			}
			if (v1[i] + arr[idx] == goal) {
				answer++;
			}
		}
		return;		
	}
	int size = v1.size();
	vector<long long> v2;
	for (int i = 0; i < size; i++) {
		int cur = v1.back();
		int n, p;
		n = cur - arr[idx];
		p = cur + arr[idx];
		v1.pop_back();
		if( 0 <= n && p <= 20) {
			v2.push_back(n);
			v2.push_back(p);
		}
		n = cur - arr[idx];
		p = cur + arr[idx];
		if (n < 0 && 0 <= p && p <= 20) {
			v2.push_back(p);
		}
		if (p > 20 && 0 <= n && n <= 20) {
			v2.push_back(n);
		}
	}
	unique(v2.begin(), v2.end());
	find(v2, idx + 1);
	return;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	v.push_back(arr[1]);
	goal = arr[N];
	find(v, 2);
	cout << answer<< '\n';
}