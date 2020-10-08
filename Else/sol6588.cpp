#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int check[1000001];
vector<int> prime;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << "A";
	memset(check, 1, sizeof(check));
	cout << "A";
	for (int i = 2; i<= 1000; i++) {
		if (check[i] != 0) {
			for (int j = i + i; j <= 1000000; j += i) {
				check[j] = 0;
			}
		}
	}
	cout << "A";
	for (int i = 3; i <= 1000000; i++) {
		if (check[i] == 1) {
			prime.push_back(i);
		}
	}
	cout << "A";
	while(1) {
		cout << "A";
		int n;
		cin >> n;
		cout << "A";
		if (n == 0) return 0;
		cout << "A";
		int idx = 0;
		int fst;
		while(1) {
			fst = prime[idx];
			if (n - fst < 0) {
				cout << "NEVER\n";
				break;
			}
			else {
				if (check[n - fst] == 1) {
					cout << n << " = " << fst << " + " << n-fst << '\n';
					break;
				}
			}
			idx++;
		}
	}
}