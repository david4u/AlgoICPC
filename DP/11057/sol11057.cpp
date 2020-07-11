#include <iostream>

using namespace std;

int N;
int endNum[1001][10];

void set() {
    for (int i = 0; i < 10; i++) {
        endNum[1][i] = 1;
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j< 10; j++) {
            for (int k = 0; k <= j; k++) {
                endNum[i][j] = (endNum[i][j] + endNum[i-1][k]) % 10007;
            }
        }
    }
}

int main() {
    cin >> N;
    if ( N == 1) {
        cout << 10 << '\n';
        return 0;
    }
    set();
    int result = 0;
    for (int i = 0; i < 10; i++) {
        result = (result + endNum[N][i]) % 10007;
    }
    cout << result << '\n';
}