#include <iostream>
#include <cstring>

using namespace std;

int N;
char arr[201];
const int mod = 100000;
long long dp[201][201];
string open = "({[";
string close = ")}]";

long long solve(int start, int end) {
	if (start > end) {
		return 1;
	}
	long long& ret = dp[start][end];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	for (int i = start +1; i <= end; i+= 2) {
		for (int k = 0; k < 3; k++) {
			if (arr[start] == open[k] || arr[start] == '?') {
				if (arr[i] == close[k] || arr[i] == '?') {
					long long tmp = 0;
					tmp = solve(start + 1, i - 1) * solve(i+1, end);
					ret += tmp;
					if (ret >= mod) {
						ret %= mod;
						ret += mod;
					}
				}
			}
		}
	}
	return ret;
}

int main() {
	cin >> N;
	if (N % 2 != 0) {
		cout << 0 << '\n';
		return 0;
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	long long answer = solve(1, N);

	if (answer < mod) {
		cout << answer << '\n';
		return 0;
	}
	printf("%05lld", answer % mod);
}