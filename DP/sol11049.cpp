#include <iostream>

using namespace std;

long long dp[501][501];
int N, r, c;
pair<int, int> mat[501];

int min(int x, int y) {
	return x < y ? x : y;
}

int main() {
	cin >> N;
	for (int i = 1;i <= N ;i++) {
		cin >> r >> c;
		mat[i] = {r, c};
	}
	for (int i = 1; i < N; i++) {
		dp[i][i+1] = mat[i].first * mat[i].second * mat[i+1].second;
	}
	for (int dif = 2; dif <= N-1; dif++) {
		for (int i = 1; i <= N-dif; i++) {
			dp[i][i+dif] = dp[i+1][i+dif] + mat[i].first * mat[i].second * mat[i+dif].second;
			for (int k = 1; k <=dif-1; k++) {
				dp[i][i+dif] = min(dp[i][i+dif] , dp[i][i+k] + dp[i+k+1][i+dif] + mat[i].first * mat[i+k].second * mat[i+dif].second);
			}
		}
	}
	cout << dp[1][N] << '\n';
}