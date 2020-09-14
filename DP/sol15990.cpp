#include <iostream>

using namespace std;
using ull = unsigned long long;

int T, n;
ull dp[100001][4];
ull mod = 1000000009;

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> T;
	dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
	for (int i = 4; i <= 100000; i++) {
		if (i-1 >= 0) {
			dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % mod;
		}
		if (i-2 >= 0) {
			dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % mod;
		}
		if (i-3 >= 0) {
			dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % mod;
		}
	}
	while (T--) {
		cin >> n;
		cout << (dp[n][1] % mod+ dp[n][2] % mod + dp[n][3] % mod) % mod << '\n';
	}


    return 0;
}