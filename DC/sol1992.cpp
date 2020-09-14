#include <iostream>

using namespace std;

int map[65][65];
int N;

void solve(int r, int c, int size) {
	int cur = map[r][c];
	bool check = true;

	if(size == 1) {
		cout << cur;
		return;
	}

	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			if (map[i][j] != cur) {
				check = false;
			}
		}
	}
	if (check) {
		cout << cur;
		return;
	}

	cur = map[r][c];
	check = true;
	for (int i = r; i < r+size/2; i++) {
		for (int j = c; j < c+size/2; j++) {
			if (map[i][j] != cur) {
				cout << "(";
				solve(r, c, size/2);
				cout << ")";
				i = 65;
				j = 65;
				check = false;
			}
		}
	}
	if (check) {
		cout << cur;
	}

	cur = map[r][c+size/2];
	check= true;
	for (int i = r; i < r+size/2; i++) {
		for (int j = c+size/2; j < c + size; j++) {
			if (map[i][j] != cur) {
				cout << "(";
				solve(r, c+size/2, size/2);
				cout << ")";
				i = 65;
				j = 65;
				check = false;
			}
		}
	}
	if (check) {
		cout << cur;
	}

	cur = map[r+size/2][c];
	check = true;
	for (int i = r+size/2; i < r +size; i++) {
		for (int j = c; j < c+size/2; j++) {
			if (map[i][j] != cur) {
				cout << "(";
				solve(r+size/2, c, size/2);
				i = 65;
				j = 65;
				cout << ")";
				check = false;
			}
		}
	}
	if (check) {
		cout << cur;
	}

	cur = map[r+size/2][c+size/2];
	check = true;
	for (int i = r+size/2 ; i < r + size; i++) {
		for (int j = c + size/2 ; j < c + size; j++)
			if (map[i][j] != cur) {
				cout << "(";
				solve(r+size/2, c+size/2, size/2);
				i = 65;
				j = 65;
				cout << ")";
				check = false;
			}
	}

	if (check) {
		cout << cur;
	}
}

int main() {
	cin >> N;
	string buff;
	for (int i = 1; i <= N; i++) {
		cin >> buff;
		for (int j = 1 ; j <= N; j++) {
			map[i][j] = buff[j-1] - '0';
		}
	}
	int ex = map[1][1];
	bool doit = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 1 ; j <= N; j++) {
			if (map[i][j] != ex) {
				doit = true;
			}
		}
	}
	if (!doit) {
		cout << ex;
		return 0;
	}
	cout << "(";
	solve(1, 1, N);
	cout << ")";
}