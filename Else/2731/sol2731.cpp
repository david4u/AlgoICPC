#include <iostream>

using namespace std;

using ll = unsigned long long;

ll digit[15], number;

int main() {
	int T;
	digit[0] = 1;
	for (int i = 1; i < 15; i++) {
		digit[i] = digit[i-1]*10;
	}
	

}