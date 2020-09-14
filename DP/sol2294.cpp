#include <iostream>
#include <cstring>

using namespace std;

int min(int x,  int y) {
	return x > y ? y : x;
}

int main() {
	int n, k;
	int coin[101];
	int dp[10001];
	cin >> n >> k;
	int i, j;
	dp[0] = 0;
	for (i = 1; i <= k ; ++i) {
		dp[i] = 10001;
	}

	for (i = 1; i <= n; ++i) {
		cin >> coin[i];
		// dp[coin[i]] = 1; 이거 런타임에러.
		for (j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j-coin[i]] + 1);
		}
	}
	if (dp[k] == 10001) {
		cout << -1 << '\n';
		return 0;
	}
	cout << dp[k] << '\n';
}