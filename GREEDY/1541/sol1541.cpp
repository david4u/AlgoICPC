#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;
	int ans = 0;
	string tmp = "";
	bool m = false;
	for (int i = 0 ; i <= str.size(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
			if (m) {
				ans -= stoi(tmp);
			}
			else {
				ans += stoi(tmp);
			}
			tmp = "";
			if (str[i] == '-') {
				m = true;
			}
			continue;
		}
		tmp += str[i];
	}
	cout << ans << '\n';
}