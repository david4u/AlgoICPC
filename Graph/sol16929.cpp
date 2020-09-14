#include <iostream>

using namespace std;

int N, M;
char m[51][51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N ;i++) {
		for (int j = 1; j<= M; j++) {
			char next;
			cin >> next;
			m[i][j] = next;
		}
	}
}