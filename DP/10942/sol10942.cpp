#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int arr[2001];
bool dp[2001][2001];

int main() {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	memset(dp, 0, sizeof(dp));

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	dp[N][N] = true;
	for (int i =1; i < N; i++) {
		dp[i][i] = true;
		if (arr[i] == arr[i + 1]) {
			dp[i][i+1] = true;
		}
	}
	for (int i = 2; i < N; i++) {
		for (int j = 1; j <= N-i; j++) {
			int last = i + j;
			if (arr[j] == arr[last] && dp[j+1][last-1] == true) {
				dp[j][last] = true;
			}
		}
	}

	cin >> M;
	while(M--) {
		int from, to;
		cin >> from >> to;
		cout << dp[from][to] << '\n';
	}

}