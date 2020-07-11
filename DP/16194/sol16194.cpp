#include <iostream>

using namespace std;

long long dp[1001];
long long cost[1001];
int N;

int min(int x, int y) {
	return x > y ? y : x;
}

int main() {
	cin >> N;
	for (int i = 1; i<= N; i++) {
		cin >> cost[i];
	}
	dp[1] = cost[1];
	dp[2] = min(cost[1] + cost[1], cost[2]);
	for (int i = 1; i<= N; i++) {
		dp[i] = cost[i];
		for (int j = 1; j < i; j++) {
			dp[i] = min(dp[i], dp[i-j] + cost[j]);
		}
	}
	cout << dp[N];
}