#include <iostream>

using namespace std;
using ll = long long;

int N, K;
int coin[101];
int dp[10001];

int main() {
	cin >> N >> K;
	for(int i = 1; i <= N; i++) {
		cin >> coin[i];
	}
	dp[0] = 1;
	for (int i =1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (coin[i] <= j) {
				dp[j] += dp[j-coin[i]];
			}
		}
	}
	cout << dp[K] << '\n';

}