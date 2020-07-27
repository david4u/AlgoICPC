#include <iostream>

using namespace std;

int T, K;
int ch[501];
unsigned long long dp[501][501];
int sum[501][501];

int min(int x, int y) {
	return x > y ? y : x;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> K;
		for (int i = 1; i <= K; i++) {
			cin >> ch[i];
		}
		for (int i = 1; i <= K; i++) {
			dp[i][i] = 0;
			dp[i][i+1] = ch[i]+ch[i+1];
		}
		for (int i = 1; i <= K; i++) {
			sum[i][i] = ch[i];
		}
		for (int i = 1; i < K; i++) {
			for(int j = i + 1; j <= K; j++) {
				sum[i][j] = sum[i][j-1] + ch[j];
			}
		}
		for (int dif = 2; dif <= K-1; dif++) {
			for (int j = 1; j <= K - dif; j++) {
				int from, to;
				from = j;
				to = j + dif;
				dp[from][to] = sum[from][from] + dp[from+1][to] + sum[from+1][to];
				for (int k = 1; k < dif; k++) {
					dp[from][to] = min(dp[from][to], dp[from][from + k] + sum[from][from + k] + sum[from + k + 1][to] + dp[from+k+1][to]);
				}
				dp[from][to] = min(dp[from][to], dp[from][to - 1] + sum[from][to-1] + ch[to]);
			}
		}
		cout << dp[1][K] << '\n';
	}
}