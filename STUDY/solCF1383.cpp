#include <iostream>
#include <deque>
#include <tuple>
#include <algorithm>

using namespace std;

string input;
int arr[10001];
int gap[10001];
deque<tuple<int, int, int>> d;

int main() {
	int T;
	cin >> T;
	int n;
	while (T--) {
		cin >> n;
		string input;
		cin >> input;
		for (int i = 1; i<= n; i++) {
			arr[i] = input[i-1];
		}
		cin >> input;
		for (int i = 1 ; i<= n ;i++) {
			gap[i] = input[i-1] - arr[i];
		}
		bool finish = true;
		for (int i = 1; i<= n; i++) {
			if (gap[i] != 0) {
				finish = false;
				break;
			}
		}
		for (int i = 1; i <= n; i++) {
			d.push_back(make_tuple(arr[i], gap[i], i));
		}
		sort(d.begin(), d.end());
		while (!finish) {
			for (int i = 0; i < n ;i++) {
				if (get<1>(d[0]) == 0) {
					d.pop_front();
				} else {
					break;
				}
			}
			
		}
	}
}