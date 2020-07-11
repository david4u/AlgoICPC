#include <iostream>

using namespace std;

int N;
int tri[501][501];
int dp[501][501];

int max( int x, int y ) {
	return x > y ? x : y;
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i ; j++) {
			cin >> tri[i][j];
		}
	}
	dp[1][1] = tri[1][1];
	dp[2][1] = tri[1][1] + tri[2][1];
	dp[2][2] = tri[1][1] + tri[2][2];
	for (int i = 3; i<= N; i++) {
		for (int j = 1; j <= i; j++) {
			if ( j == 1 ) {
				dp[i][j] =dp[i-1][j] + tri[i][j];
			}
			else if (j == i) {
				dp[i][j] = dp[i-1][j-1] + tri[i][j];
			}
			else {
				dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]);
				dp[i][j] = dp[i][j] + tri[i][j];
			}
		}
	}
	int ans = dp[N][1];
	for (int i = 2;i <= N; i++) {
		ans = max(ans, dp[N][i]);
	}
	cout << ans << '\n';
}