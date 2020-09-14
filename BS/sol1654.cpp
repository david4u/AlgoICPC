#include <iostream>
#include <algorithm>

using namespace std;

long long arr[10001];
long long K, N;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K >> N;
	long long right = 0;
	for (long long i = 1; i<= K; i++) {
		cin >> arr[i];
		if (arr[i] > right) {
			right = arr[i];
		}
	}
	// bianry search start
	long long left = 1;
	long long ans = 0;

	while (left <= right) {
		
		long long mid = (left + right) /2 ;

		// cnt 는 가져갈 수 있는 랜선 수
		long long cnt = 0;

		for (long long i = 1; i <= K; i++) {
			cnt += arr[i] / mid;
		}

		// 통과되는 경우에는 기준을 높여서 최대값 찾기
		if (cnt >= N) {
			ans = mid;
			left = mid + 1;
		}
		else {
			// 통과되지 않는 경우는 기준을 낮춰서 다시 찾기
			right = mid - 1;
		}
	}

	cout << ans << '\n';
}