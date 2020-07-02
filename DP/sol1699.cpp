#include <iostream>

using namespace std;

int arr[321];

int N;

int main() {
    cin >> N;
    for (int i = 1; i <= 320; i++) {
        arr[i] = i*i;
        if (arr[i] == N) {
            cout << 1 << '\n';
            return 0;
        }
    }
    for (int i = 1; i <= 319; i++) {
        for(int j = i + 1; j <= 320; j++) {
            if (arr[i] + arr[j] == N) {
                cout << 2 << '\n';
                return 0;
            }
        }
    }
    for (int i = 1; i <= 318; i++) {
        for (int j = i+1; j<=319; j++) {
            for (int k = j+1; k<=320; k++) {
                if (arr[i] + arr[j] + arr[k] == N) {
                    cout << 3 << '\n';
                    return 0;
                }
            }
        }
    }
    cout << 4 << '\n';
}