#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int hp[4] = {0, 0, 0, 0};
int dp[61][61][61];
vector<int> dmg;

int min(int x, int y) {
	return x < y ? x : y;
}

int solve(int a, int b, int c) {
	if (a < 0) return solve(0, b, c);
	if (b < 0) return solve(a, 0, c);
	if (c < 0) return solve(a, b, 0);

	if (a == 0 && b == 0 && c == 0) {
		return 0;
	}

	int& ret = dp[a][b][c];
	if (ret != -1) {
		return ret;
	}

	ret = 100000;
	do {
		int x, y, z;
		x = dmg[0];
		y = dmg[1];
		z = dmg[2];
		ret = min(ret, solve(a - x, b - y, c - z) + 1);
	} while (next_permutation(dmg.begin(), dmg.end()));
	return ret;
}

int main() {
	dmg.push_back(1);
	dmg.push_back(3);
	dmg.push_back(9);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> hp[i];
	}
	cout << solve(hp[1], hp[2], hp[3]) << '\n';
}