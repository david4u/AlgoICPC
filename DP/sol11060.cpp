#include <iostream>
#include <cstring>

using namespace std;

int N;
int arr[1001];
int dp[1001][1001];

int min(int x, int y) {
	return x > y;
}

int solve(int num, int pos) {
	if(pos == N) {
		return num-1;
	}
	int &ret = dp[num][pos];

	if (ret != 1000) {
		return ret;
	}
	for (int i = 1; i <= arr[pos] && pos+i <= N; i++) {
		if (ret < solve(num+1, pos+i) + 1) {
			cout << solve(num+1, pos+i) +1 << " " << num+1 << " " << pos << "\n";
		}
		ret = min(ret, solve(num+1, pos+i));

	}
	return ret;
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = 1000;
		}
	}
	solve(1, 1);
	if (dp[1][1] == 1000) {
		cout << -1 << '\n';
		return 0;
	}
	cout << dp[1][1] << '\n';
	return 0;
}