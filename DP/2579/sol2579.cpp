#include <iostream>

using namespace std;

int score[301];
int dp[301];
int N;
int max(int x, int y) {
    return x > y ? x : y;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> score[i];
    }
    dp[1] = score[1];
    dp[2] = score[1] + score[2];
    dp[3] = max(score[1] + score[3], score[2] + score[3]);
    for (int i = 3; i <= N; i++) {
        dp[i] = max(dp[i-2] + score[i], dp[i-3] + score[i-1] + score[i]);
    }
    cout << dp[N] << '\n';

}