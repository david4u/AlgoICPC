#include <iostream>
#include <cstring>

using namespace std;

int N, S, M;
int dV[101];
int dp[101][1001];

int max(int x, int y) {
	return x > y ? x : y;
}

int maxV(int cv, int i) {
	if (cv < 0 || cv > M) {
		return -1000;
	}
	if (i == N) {
		return cv;
	}
	int result;
	if( dp[i][cv] != -1) {
		return dp[i][cv];
	}
	dp[i][cv] = max(maxV(cv + dV[i+1], i + 1), maxV(cv - dV[i+1], i + 1));
	return dp[i][cv];
}

int main() {
	cin >> N >> S >> M;
	for (int i = 1 ;i <= N; i++) {
		cin >> dV[i];
	}
	memset(dp, -1, sizeof(dp));
	int result = maxV(S, 0);
	if (result == -1000) {
		cout << -1 << '\n';
	} else {
		cout << result << '\n';
	}
	return 0;
}