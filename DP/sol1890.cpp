#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
long long map[101][101];
long long dp[101][101];
long long answer = 0;
bool possible[101][101];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j<= N; j++) {
			cin >> map[i][j];
		}
	}
	memset(possible,false, sizeof(possible));
	memset(dp, 0, sizeof(dp));
	dp[1][1] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j == 1) {// do nothing
			}
			for (int k = j; k >= 1; k--) {
				if(k + map[i][k] == j && map[i][k] != 0) {
					dp[i][j] += dp[i][k];
				}
			}
			for (int k = i; k >= 1; k--) {
				if(k + map[k][j] == i && map[k][j] != 0) {
					dp[i][j] += dp[k][j];
				}
			}
		}
	}
	cout << dp[N][N] << '\n';
}