#include <iostream>
#include <string>
#include <cstring>

using namespace std;
using ll = long long;

const ll mod = 100000;

int N;
string s;
ll dp[201][201];
string f = "({[";
string l = "]})";

ll solve(int start, int end) {
	if (start > end) {
		return 1;
	}
	ll &ret = dp[start][end];
	if (ret != -1) {
		return ret;
	}
	for (int i = start + 1; i <= end; i+=2) {
		for (int j = 0; j < 3; j++) {
			if (s[start] == f[j] || s[start] == '?') {
				if (s[i] == l[j] || s[i] == '?') {
					ll tmp = solve(start + 1, i - 1) * solve(i + 1, end);
					ret += tmp;
					if (ret >= mod) {
						ret = mod + ret % mod;
					}
				}
			}
		}
	}
	return ret;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> N >> s;
	memset(dp, -1, sizeof(dp));
	ll ans = solve(0, N - 1);
	if (ans >= mod) {
		cout << ans % mod << '\n';
		return 0;
	}
	cout << ans << '\n';
}