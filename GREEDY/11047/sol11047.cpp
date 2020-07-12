#include <iostream>

using namespace std;

int N;
long long cost[11];
long long K;

int main() {
	cin >> N >> K;
	for (int i = 1; i<= N; i++) {
		cin >> cost[i];
	}
	int answer = 0;
	int idx = 0;
	while (K != 0) {
		for (int i = N; i >= 1; i--) {
			if (cost[i] <= K) {
				idx = i;
				i = 0;
			}
		}
		answer += K / cost[idx];
		K = K % cost[idx];
	}
	cout << answer << "\n";
}
