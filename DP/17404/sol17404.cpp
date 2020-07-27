#include <iostream>

using namespace std;

int N;
int cost[1001][3];
int dp[1001][3];

int min(int x, int y) {
	return x < y ? x : y;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	dp[1][0] = cost[1][0];
	dp[1][1] = cost[1][1];
	dp[1][2] = cost[1][2];
	for (int i = 2; i <= N-1; i++) {
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
		dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + cost[i][2];
	}

}