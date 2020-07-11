#include <iostream>

using namespace std;

int endNum[10][101];
int N;

void set() {
    endNum[0][1] = 0;
    for (int i = 1; i < 10; i++) {
        endNum[i][1] = 1;
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= 8; j++) {
            endNum[j][i] = (endNum[j-1][i-1] + endNum[j+1][i-1])%1000000000;
        }
        endNum[0][i] = endNum[1][i-1] % 1000000000;
        endNum[9][i] = endNum[8][i-1] % 1000000000;
    }
}
int main() {
    cin >> N;
    if ( N == 1) {
        cout << 9 << '\n';
        return 0;
    }
    set();
    int result = 0;
    for (int i = 0; i <10; i++) {
        result = (result + endNum[i][N]) % 1000000000;
    }
    cout << result << '\n';
}