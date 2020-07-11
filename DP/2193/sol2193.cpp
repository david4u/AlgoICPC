#include <iostream>

using namespace std;

long long dp[2][91];

int N;

int main() {
    cin >> N;
    dp[0][1] = 0;
    dp[1][1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[0][i] = dp[0][i-1] + dp[1][i-1];
        dp[1][i] = dp[0][i-1];
    }
    cout << dp[0][N] + dp[1][N];
}