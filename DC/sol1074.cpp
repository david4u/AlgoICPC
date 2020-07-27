#include <iostream>

using namespace std;

int N;
int r, c;
int answer = -1;

int cal(int a, int b) {
	int ret = a;
	b--;
	while (b--) {
		ret *= a;
	}
	return ret;
}

void start(int x, int y, int length) {
	if (length == 1) {
		answer++;
		if (x == c+1 && y == r+1) {
			cout << answer << '\n';
		}
		return;
	}
	if (x <= c+1 && c+1 < x+length/2 && y <= r+1 && r+1 < y + length/2) {
		start(x, y, length/2);
	}
	else if (x <= c+1 && c+1 < x + length/2 && y+length/2 <= r+1 && r+1 < y +length) {
		start(x, y+length/2, length/2);
	}
	else if (x + length/2 <= c+1 && c+1 < x + length && y <= r+1 && r+1 < y+ length/2) {
		start(x+ length/2, y, length/2);
	}
	start(x, y, length/2);
	start(x + length/2, y, length/2);
	start(x, y + length/2, length/2);
	start(x + length/2, y + length/2, length/2);
}

int main() {
	cin >> N >> r >> c;
	start(1, 1, cal(2,N));
}