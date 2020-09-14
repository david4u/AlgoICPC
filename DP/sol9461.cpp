#include <iostream>

using namespace std;

long long dp[101];

int T, N;

int main() {
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;
    cin >> T;
    while (T--) {
        cin >> N;
        if (dp[N] != 0) {
            cout << dp[N] << '\n';
        } else {
            for (int i = 6; i <= N; i++) {
                dp[i] = dp[i-1] + dp[i-5];
            }
            cout << dp[N] << '\n';
        }
    }
}