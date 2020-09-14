#include <iostream>

using namespace std;

int N;
int cost[1001][3];
long long dp[1001][3][3];

long long min(long long x, long long y) {
	return x < y ? x : y;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	dp[1][0][0] = cost[1][0];
	dp[1][1][1] = cost[1][1];
	dp[1][2][2] = cost[1][2];

	dp[2][1][0] = dp[1][0][0] + cost[2][1];
	dp[2][2][0] = dp[1][0][0] + cost[2][2];

	dp[2][0][1] = dp[1][1][1] + cost[2][0];
	dp[2][2][1] = dp[1][1][1] + cost[2][2];

	dp[2][0][2] = dp[1][2][2] + cost[2][0];
	dp[2][1][2] = dp[1][2][2] + cost[2][1];
	for (int i = 3; i <= N-1; i++) {
		dp[i][0][0] = min(dp[i-1][1][0], dp[i-1][2][0]) + cost[i][0];
		dp[i][1][0] = min(dp[i-1][0][0], dp[i-1][2][0]) + cost[i][1];
		dp[i][2][0] = min(dp[i-1][1][0], dp[i-1][0][0]) + cost[i][2];
		
		dp[i][0][1] = min(dp[i-1][1][1], dp[i-1][2][1]) + cost[i][0];
		dp[i][1][1] = min(dp[i-1][0][1], dp[i-1][2][1]) + cost[i][1];
		dp[i][2][1] = min(dp[i-1][1][1], dp[i-1][0][1]) + cost[i][2];
		
		dp[i][0][2] = min(dp[i-1][1][2], dp[i-1][2][2]) + cost[i][0];
		dp[i][1][2] = min(dp[i-1][0][2], dp[i-1][2][2]) + cost[i][1];
		dp[i][2][2] = min(dp[i-1][1][2], dp[i-1][0][2]) + cost[i][2];	
	}
	long long answer = 210000000000;
	answer = min(answer, dp[N-1][1][0] + cost[N][2]);
	answer = min(answer, dp[N-1][2][0] + cost[N][1]);
	answer = min(answer, dp[N-1][0][1] + cost[N][2]);
	answer = min(answer, dp[N-1][2][1] + cost[N][0]);
	answer = min(answer, dp[N-1][1][2] + cost[N][0]);
	answer = min(answer, dp[N-1][0][2] + cost[N][1]);

	cout << answer << '\n';
}