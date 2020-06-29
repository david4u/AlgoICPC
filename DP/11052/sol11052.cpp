#include <iostream>
#include <cstring>

using namespace std;

int cost[10001];
int totalcost[1001];
int N;

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
    }
    totalcost[1] = cost[1];
    for (int i = 1; i <= N; i++) {
        for (int j =1; j <= i; j++) {
            totalcost[i] = max(totalcost[i], totalcost[i-j] +cost[j]);
        }
    }
    cout << totalcost[N];
}