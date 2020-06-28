#include <iostream>
#include <math.h>

using namespace std;

bool check[1000000];
int D[1000000];
int S[1000000];
int count = 1;
int A;
int p;
int newN;
int ans = 0;

int nextEl(int x, int p) {
	int y = 0;
	int tmp;
	while( x != 0 ) {
		tmp = x%10;
		x = x/10;
		tmp = pow(tmp, p) + 0.5;
		y = y + tmp;
	}
	return y;
}

int main() {
	cin >> A >> p;
	newN = A;
	if (A == nextEl(A,p)) {
		cout << 0;
		return 0;
	}
	while (check[newN] != true) {
		check[newN] = true;
		D[count] = newN;
		S[newN] = count;
		count++;
		newN = nextEl(newN, p);
	}

	cout << S[newN] - 1;
	
	return 0;
}