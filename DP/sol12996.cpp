#include <iostream>
#include <cstring>

using namespace std;

int S;
int arr[3];
long long dp[51][51][51][51];

// dp[n][i][j][k]
// total count : n;
// 1st, 2nd, 3rd player count i, j, k

const long long mod = 1000000007;

long long solve(int k, int x, int y, int z) {

	// exit point
	if (x + y + z < k) {
		dp[k][x][y][z] = 0;
		return 0;
	}
	if ( x > k || y > k || z > k || x < 0 || y < 0 || z < 0) {
		dp[k][x][y][z] = 0;
		return 0;
	}

	// memoization
	long long& ret = dp[k][x][y][z];

	if (ret != -1) {
		return ret;
	}

	// calculate ret
	ret = 0;
	for (int dx = 0; dx <= 1; dx++) {
		for (int dy = 0; dy<= 1; dy++) {
			for (int dz = 0; dz <= 1; dz++) {
				if (dx == 0 && dz == 0 && dy == 0) {}
				else {
					ret += solve(k-1, x-dx, y-dy, z-dz);
					ret %= mod;
				}
			}
		}
	}
	return ret;
}
int main() {
	cin >> S;
	memset(dp, -1, sizeof(dp));

	// input
	for (int i = 0; i < 3; i++){
		cin >> arr[i];
	}

	// trivial solution
	if ( arr[0] + arr[1] + arr[2] < S) {
		cout << 0 << '\n';
		return 0;
	}
	
	// trivial dp setting
	for (int i = 1;i <= S; i++) {
		dp[i][0][0][i] = 1;
		dp[i][i][0][0] = 1;
		dp[i][0][i][0] = 1;
	}
	for (int i = 0; i <= 1; i++) {
	
		for (int j = 0; j <= 1; j++) {
			for (int k = 0; k <= 1; k++) {
				dp[1][i][j][k] = 1;
			}
		}
	}
	dp[0][0][0][0] = 1;
	dp[1][0][0][0] = 0;
	
	cout << solve(S, arr[0], arr[1], arr[2]) % mod;
}