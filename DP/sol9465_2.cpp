#include <iostream>

using namespace std;

int st[2][100001];
int dp[2][100001];

int n;
int T;

int max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> st[0][i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> st[1][i];
		}
		dp[0][1] = st[0][1];
		dp[1][1] = st[1][1];
		dp[0][2] = st[1][1] + st[0][2];
		dp[1][2] = st[0][1] + st[1][2];
		for (int i = 3; i <= n; i++) {
			dp[0][i] = max(dp[1][i-2], dp[1][i-1]) + st[0][i];
			dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + st[1][i];
		}
		cout << max(dp[0][n], dp[1][n]) << '\n';
	}
	return 0;
}