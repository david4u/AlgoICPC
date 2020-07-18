#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(char a, char b) {
	return a > b;
}

int main() {
	string S;
	cin >> S;

	long long sum = 0;
	bool z = false;
	for (int i = 0; i< S.size(); i++) {
		sum += (S[i] - '0');
		if ((S[i]-'0') == 0) {
			z = true;
		}
	}

	if (sum % 3 || !z) {
		cout << -1 << '\n';
	}
	else {
		sort(S.begin(), S.end(), cmp);
		cout << S << '\n';
	}
}