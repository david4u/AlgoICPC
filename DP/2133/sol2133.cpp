#include <iostream>

using namespace std;

int dp[16];
int N;

int main() {
    cin >> N;
    if (N % 2 != 0) {
        cout << 0 << '\n';
        return 0;
    }
    dp[1] = 3;
    dp[2] = 11;
    for (int i = 3; i <= N/2; i++) {
        dp[i] = dp[i-1] * 3 + 2;
        for (int j = i - 2; j > 0; j--) {
            dp[i] += dp[j] * 2;
        }
    }
    cout << dp[N/2] << '\n';
}