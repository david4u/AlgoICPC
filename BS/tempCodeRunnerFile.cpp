#include <iostream>
#include <algorithm>

using namespace std;

long long arr[10001];
long long K, N;

int main() {
	cin >> K >> N;
	for (long long i = 1; i<= K; i++) {
		cin >> arr[i];
	}

	long long left = 1;
	long long right = 1000001;
	long long ans = 0;
	while (left <= right) {
		long long mid = (left + right) /2 ;
		long long cnt = 0;
		for (long long i = 1; i <= K; i++) {
			cnt += arr[i] / mid;
		}
		if (cnt >= N) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans << '\n';

}