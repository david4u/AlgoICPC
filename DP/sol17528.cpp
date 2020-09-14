#include <iostream>
#include <cstring>

using namespace std;

int N;
int a[251];
int b[251];

int dp[251][62501];

int min(int x , int y) {
	return x < y ? x : y;
}
int max(int x, int y) {
	return x > y ? x : y;
}
int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> a[i] >> b[i];
	}

	for (int i = 0; i <= 250; i++) {
		for (int j = 0; j <= 62500; j++) {
			dp[i][j] = 987654321;
		}
	}
	dp[1][a[1]] = 0;
	dp[1][0] = b[1];

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 62500; j++) {
			if (dp[i-1][j] == 987654321) continue;
			dp[i][j + a[i]] = min(dp[i][j+a[i]], dp[i-1][j]);
			dp[i][j] = min(dp[i][j], dp[i-1][j] + b[i]);
		}
	}
	int ans = 987654321;
	for (int i = 0; i <= 62500; i++) {
		ans = min(ans, max(i, dp[N][i]));
	}
	cout << ans;

}