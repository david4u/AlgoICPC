#include <iostream>

using namespace std;

bool abc[26];
string prob;
int T;
string answer;
bool term = false;

int main() {
	cin >> T;
	while (T--) {
		term = false;
		int size;
		cin >> size;
		for (int i = 0; i < 26; i++) {
			abc[i] = false;
		}
		cin >> prob >> answer;
		for (int i = 0; i < size; i++) {
			if (prob[i] != answer[i]) {
				abc[prob[i] - 'a'] = true;
			}
			if (prob[i] > answer[i]) {
				if (term) continue;
				cout << -1 << '\n';
				term = true;
			}
		}
		int cnt = 0;
		for (int i = 0; i < 26; i++) {
			if (abc[i] == true) {
				cnt++;
			}
		}
		if (!term) {
			cout << cnt << '\n';
		}
	}
}