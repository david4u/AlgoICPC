#include <iostream>

using namespace std;

int N;
int lt[10001];
int dp[10001];

int max(int x, int y) {
    return x > y ? x : y;
}

int final_max(int x, int y, int z, int q) {
    if (x > y && x > z && x > q) return x;
    if (y > x && y > z && y > q) return y;
    if (z > x && z > y && z > q) return z;
    if (q > x && q > y && q > z) return q;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> lt[i];
    }
    dp[1] = lt[1];
    dp[2] = lt[1] + lt[2];
    for (int i = 3; i<= N; i++) {
        dp[i] = max(dp[i-3] + lt[i-1] + lt[i], dp[i-2] + lt[i]);
        dp[i] = max(dp[i-1], dp[i]);
    }
    if (N == 1) {
        cout << lt[1]; 
        return 0;
    }
    if (N == 2) {
        cout << lt[1] + lt[2];
        return 0;
    }
    if (N == 3) {
        cout << final_max(lt[1]+lt[2], lt[1] + lt[3],lt[2] + lt[3], 0);
        return 0;
    }
    cout << final_max(dp[N-3], dp[N-2], dp[N-1], dp[N]);
}