#include <iostream>

using namespace std;

int N;
int r, c;
int answer = 0;

int cal(int a, int b) {
	int ret = a;
	b--;
	while (b--) {
		ret *= a;
	}
	return ret;
}

void start(int x, int y, int length) {
	if (length == 2) {
		if (y == r && x == c) {
			cout << answer << '\n';
			return ;
		}
		answer++;
		if (y == r && x +1 == c) {
			cout << answer << '\n';
			return;
		}
		answer++;
		if (y +1 == r && x == c ) {
			cout << answer << '\n';
			return;
		}
		answer++;
		if (y +1 == r && x + 1== c) {
			cout << answer << '\n';
			return;
		}
		answer++;
		return;
	}
	start(x, y, length/2);
	start(x + length/2, y, length/2);
	start(x, y+length/2, length/2);
	start(x + length/2, y + length/2, length/2);
}

int main() {
	cin >> N >> r >> c;
	start(0, 0, cal(2,N));
}