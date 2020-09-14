#include <iostream>
#include <algorithm>

using namespace std;

int arr[10];

int main() {
    for (int i = 1; i <= 9; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + 10);
    int sum = 0;
    for (int i = 1; i <= 9; i++) {
        sum += arr[i];
    }
    for (int i = 1; i <= 8; i++) {
        for (int j = i +1; j <= 9; j++) {
            if (sum - arr[i] - arr[j] == 100) {
                for (int k = 1; k <= 9; k++) {
                    if (k != i && k != j) {
                        cout << arr[k] << '\n';
                    }
                }
                return 0;
            }
        }
    }
}