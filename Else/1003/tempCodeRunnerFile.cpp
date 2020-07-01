#include <iostream>

using namespace std;

int N;
int T;

int dp[41];
int main() {
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (i = 3; i <= 40; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cin >> T;
    while (T--) {
        cin >> N;
        cout << dp[N-1] << " " << dp[N] << '\n';
    }
}