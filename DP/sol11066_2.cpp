#include <iostream>
#include <cstring>

using namespace std;

int T, K;
int ch[501];
long long dp[501][501];

int min(int x, int y) {
	return x < y ? x : y;
}

int main() {

	cin >> T;

	while(T--) {
		memset(ch, 0, sizeof(ch));
		memset(dp, 0, sizeof(dp));
		cin >> K;
		ch[0] = 0;
		for (int i = 1; i <= K; i++) {
			int chap;
			cin >> chap;
			ch[i] = ch[i-1] + chap;
			dp[i][i] = 0;
		}
		for (int i = 1; i < K ;i++) {
			dp[i][i+1] = ch[i+1] - ch[i-1];
		}
		
		for (int dif = 2; dif <= K-1; dif++) {
			for (int i = 1; i <= K-dif; i++) {
				dp[i][i+dif] = ch[i] - ch[i-1] + dp[i+1][i+dif] + ch[i+dif] - ch[i];
				for (int j = i + 1 ; j <= i+dif-1; j++) {
					dp[i][i+dif] = min(dp[i][i+dif], dp[i][j] + dp[j+1][i+dif] + ch[j] - ch[i-1] + ch[i+dif] - ch[j]);
				}
			}
		}
		
		cout << dp[1][K] << '\n';
	}
}