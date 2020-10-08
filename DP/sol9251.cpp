#include <iostream>
#include <cstring>

using namespace std;

string X, Y;
int dp[1001][1001];

int main() {
	cin >> X >> Y;
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			dp[i][j] = 0;
		}
	}
	int x = X.length();
	int y = Y.length();
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			if (X[i-1] == Y[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else if (dp[i-1][j] > dp[i][j-1]) {
				dp[i][j] = dp[i-1][j];
			}
			else {
				dp[i][j] = dp[i][j-1];
			}
		}
	}
	cout << dp[x][y] << '\n';
}