#include <iostream>
#include <cstring>

using namespace std;

int cache[12];
int T;

int main() {
    cin >> T;
    int p;
    memset(cache, -1, sizeof(cache));
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;
    for (int i = 4; i <= 11; i++) {
        cache[i] = cache[i-1] + cache[i-2] + cache[i-3];
    }
    for (int i = 0; i < T; i++) {
        cin >> p;
        cout << cache[p] << '\n';
    }
}