#include <iostream>

using namespace std;

int N;
int arr[1001];
int dp[1001];

int bigger(int x, int y) {
    return x > y ? x : y;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= N; i++) {
        int max = 0;
        for (int j = 1; j <= i; j++) {
            if (arr[j] < arr[i]) {
                max = bigger(max, dp[j]);
            }
        }
        dp[i] = max + 1;
    }
    int max = 1;
    for (int i = 1; i <= N; i++) {
        max = bigger(max, dp[i]);
    }
    cout << max << '\n';
    return 0;
}