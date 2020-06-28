#include <iostream>

using namespace std;

int s[16];
int days;
long long coin = 0;
long long won;

int main() {
    cin >> days >> won;
    for (int i = 1 ; i <= days; i++) {
        cin >> s[i];
    }
    for (int i = 1; i < days; i++) {
        cout << i << "day\n";
        if ((s[i] < s[i+1])&&(won/s[i] != 0)) {
            coin = coin + won / s[i];
            cout << won/s[i] << "buy\n";
            won = won - coin*s[i];
        }
        if (s[i] > s[i+1]) {
            long long tmp = coin*s[i];
            cout << tmp << "get\n";
            won = won + tmp;
            coin = 0;
        }
        cout << coin << '\n' << won << '\n';
    }
    won = won + coin*s[days];
    cout << won << '\n';
    return 0;
}