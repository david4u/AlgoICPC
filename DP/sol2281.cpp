#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int arr[1001];
int dp[1001][1001]; // dp[i][j] 는 i명이 남은 상황에서 j칸을 사용한 경우.

int min(int x, int y) {
	return x < y ? x : y;
}

int solve(int i , int j) {
	if (i == 0) {
		return 0;
	}
	int& ret = dp[i][j];
	if (ret != -1) {
		return ret;
	}
	if (arr[n-i+1] + j + 1 <= m) {
		ret = min(solve(i - 1, j + arr[n-i+1] + 1), solve(i-1, arr[n-i+1]) + (m-j)*(m-j));
	} else {
		ret = solve(i-1, arr[n-i+1]) + (m-j)*(m-j);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1 ; i <= n; i++) {
		cin >> arr[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(n-1, arr[1]);
}