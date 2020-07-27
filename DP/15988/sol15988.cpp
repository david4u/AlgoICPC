#include <iostream>

using namespace std;
using ull = unsigned long long;
ull mod = 1000000009;
ull dp[1000001];

int main() {
	int T, n;
	cin >> T;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 1000000; i++) {
		dp[i] = (dp[i-1] % mod + dp[i-2] % mod + dp[i-3] % mod)%mod;
	}
	while (T--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
}