#include <iostream>

using namespace std;


long long bino[401][201];
int N;
int K;

long long fillBino(int n, int r) {
    if (n == r || r == 0) return 1;
    if (bino[n][r] != 0) return bino[n][r];
    long long ret = fillBino(n-1, r-1) + fillBino(n-1, r);
    bino[n][r] = ret;
    return ret;
}

int main() {
    cin >> N;
    cin >> K;
    cout << fillBino(K+N-1, N);

    return 0;
}