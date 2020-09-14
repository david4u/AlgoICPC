#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[1001];
int dp[1001][1001];
vector<int> v;

int main() {
	cin >> N;
	for (int i = 1; i<= N; i++) {
		char tmp;
		cin >> tmp;
		switch(tmp) {
			case 'B':
				arr[i] = 1;
			case 'O':
				arr[i] = 2;
			case 'J':
				arr[i] = 3;
			default:
				arr[i] = 1;
		}
	}
}