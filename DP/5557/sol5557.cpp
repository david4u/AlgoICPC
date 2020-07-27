#include <iostream>
#include <cstring>
using namespace std;

using ll = long long;

int N;
int arr[101];
ll dp[101][21];
// i 번째 까지 실행했을 때 값이 j인 경우의 수 -> d[i][j]
// N-1번째 까지 실행했을 때 값이 arr[N]인 경우의 수가 answer;
ll answer = 0;

void setdp(int idx) {
	if (idx == N) {
		return;
	}
	for (int i = 0; i <= 20; i++) {
		if(dp[idx-1][i] != 0) {
			if(i + arr[idx] <= 20) {
				dp[idx][i + arr[idx]] += dp[idx-1][i];
			}
			if (i-arr[idx] >= 0) {
				dp[idx][i - arr[idx]] += dp[idx-1][i];
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	memset(dp, 0, sizeof(dp));
	dp[1][arr[1]] = 1;
	for (int i = 2; i <= N; i++) {
		setdp(i);
	}
	answer = dp[N-1][arr[N]];
	cout << answer << '\n';
}
