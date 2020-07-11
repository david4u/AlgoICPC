#include <iostream>

using namespace std;



int N;

int arr[100001];
int dp[100001];

int bigger(int x, int y) {
    return x > y ? x : y;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    int answer = arr[1];
    dp[1] = arr[1];
    for (int i = 2; i <= N; i++) {
        dp[i] = bigger(dp[i-1] + arr[i], arr[i]);
        answer = bigger(dp[i], answer);
    }
    cout << answer << '\n';
}