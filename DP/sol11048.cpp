#include <iostream>
#include <cstring>

using namespace std;

int N, M;
long long dp[1001][1001];
int map[1001][1001];

long long max(long long x, long long y) {
	return x > y ? x : y;
}

int main() {
	memset(dp, 0, sizeof(dp));
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	dp[1][1] = map[1][1];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + map[i][j];
		}
	}
	cout << dp[N][M] << '\n';
}