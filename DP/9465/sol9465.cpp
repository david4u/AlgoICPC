#include <iostream>

using namespace std;

int T;
int N;
int arr[2][100000];
int mxv[2][100000];

int max(int x, int y) {
    return x > y ? x : y;
}

int main() {
    cin >> T;
    while(T--) {
        cin >> N;
        for (int i = 0 ; i < N; i++) {
            cin >> arr[0][i];
        }
        for (int i = 0; i < N; i++) {
            cin >> arr[1][i];
        }
        mxv[0][0] = arr[0][0];
        mxv[1][0] = arr[1][0];
        mxv[0][1] = arr[0][1] + mxv[1][0];
        mxv[1][1] = arr[1][1] + mxv[0][0];
        for (int i = 2; i < N; i++) {
            mxv[0][i] = max(mxv[1][i-1], mxv[1][i-2]) + arr[0][i];
            mxv[1][i] = max(mxv[0][i-1], mxv[0][i-2]) + arr[1][i];
        }
        cout << max(mxv[0][N-1], mxv[1][N-1]) << '\n';

    }
}