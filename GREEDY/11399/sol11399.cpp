#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1000];

int main() {
	cin >> N;
	for (int i = 0; i< N ;i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int answer = 0;
	for (int i = 0; i < N; i++) {
		answer += (N-i) * arr[i];
	}
	cout << answer << '\n';
}