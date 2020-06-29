#include <iostream>
#include <cstring>

using namespace std;

int cache[1001];
int N;

int solve(int x) {
    if ( x == 1) return 1;
    if ( x == 2) return 3;
    if ( cache[x] != -1) return cache[x];
    int ret;
    ret = (solve(x-1) + solve(x-2) + solve(x-2)) % 10007;
    cache[x] = ret;
    return ret;
    
}

int main() {
    cin >> N;
    memset(cache, -1, sizeof(cache));
    cache[1] = 1;
    cache[2] = 3;
    cout << solve(N) << '\n';
}