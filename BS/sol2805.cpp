#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
unsigned long long M;

unsigned long long arr[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(arr, 0, sizeof(arr));
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	unsigned long long left, right, mid, answer;
	left = 1;
	answer = 0;
	mid  =0;
	right = 2000000000;
	while ( left <= right) {
		mid = (left + right) /2;
		unsigned long long tmp = 0;
		for (int i = 1; i<=N; i++) {
			if (arr[i] > mid) {
				tmp += arr[i] - mid;
			}
		}
		if (tmp < M) {
			right = mid - 1;
		} else {
			if (answer < mid) {
				answer = mid;
			}
			left = mid + 1;
		}
	}
	cout << answer << '\n';
}