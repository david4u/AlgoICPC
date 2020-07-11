#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[1001];
int dp[1001];
int back[1001];

int bigger(int x, int y) {
    return x > y ? x : y;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= N; i++) {
        int max = 0;
        for (int j = 1; j <= i; j++) {
            if (arr[j] < arr[i]) {
				if (dp[j] > max) {
					max = dp[j];
					back[i] = j;
				}
            }
        }
        dp[i] = max + 1;
    }
    int max = 1;
	int maxidx = 1;
	for (int i = 1; i <= N; i++) {
		if (dp[i] > max) {
			max = dp[i];
			maxidx = i;
		}
	}
	cout << max << '\n';
	vector<int> result;
	for (int i = 0; i < max; i++) {
		result.push_back(arr[maxidx]);
		maxidx = back[maxidx];
	}
	sort(result.begin(), result.end());
	for (int i = 0; i < max; i++) {
		cout << result[i] << " ";
	}
}