#include <iostream>

using namespace std;

int carry;
int n;
int arr[50001];
int ssum[50001];
int dp[4][50001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cin >> carry;

	for (int i = carry; i <= n ;i++) {
		int tmp = 0;
		for (int j = i; j >= i-carry+1; j--) {
			tmp += arr[j];
		}
	}
	for (int k = carry; k <= n; k++) {
		dp[1][k] = ssum[k];
	}
	for (int i = carry; i <= n; i++) {
		dp[2][]
	}

}