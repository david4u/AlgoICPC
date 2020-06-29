#include <iostream>

using namespace std;

int arr[1000001];
int N;

int min(int x, int y) {
    if (x > y) return y;
    return x;
}
void set() {
    arr[1] = 0;
    for (int i = 2; i<=1000000; i++) {
        arr[i] = arr[i-1] + 1;
        if (i%3 == 0) {
            arr[i] = min(arr[i], arr[i/3] + 1);
        }
        if (i%2 == 0) {
            arr[i] = min(arr[i], arr[i/2] + 1);
        }
    }
}

int main() {
    cin >> N;
    set();
    cout << arr[N];
}