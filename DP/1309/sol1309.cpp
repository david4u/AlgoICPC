#include <iostream>

using namespace std;

int N;
long long dp[100001][3];
int mod = 9901;

int main() {
	cin >> N;
	dp[1][1] = 1;
	dp[1][2] = 1;
	dp[1][0] = 1;
	for (int i = 1; i< N; i++) {
		dp[i+1][0] = (dp[i][1] + dp[i][2] + dp[i][0]) % mod;
		dp[i+1][1] = (dp[i][2] + dp[i][0]) % mod;
		dp[i+1][2] = (dp[i][0] + dp[i][1]) % mod;
	}
	cout << ( dp[N][0] + dp[N][1] + dp[N][2] ) % mod << '\n';
}