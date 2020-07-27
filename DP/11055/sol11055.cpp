#include <iostream>

using namespace std;
int N;
int arr[1001];
int dp[1001];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> N;
	int max = 0;
	for(int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for(int i = 1; i<= N; i++) {
		dp[i] = arr[i];
		for (int j = 1; j <= i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i]) {
				dp[i] = dp[j] + arr[i];
			}
		}
		if (max < dp[i]) max = dp[i];
	}
	cout << max << '\n';
}