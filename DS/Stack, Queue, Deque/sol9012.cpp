#include <iostream>

using namespace std;

string input;
int check = 0;
int T;
bool pass;

int main() {
    cin >> T;
    while ( T--) {
        cin >> input;
        check = 0;
        pass = false;
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '(') {
                check++;
            } else {
                if (check <= 0) {
                    cout << "NO" << '\n';
                    i = input.length();
                    pass = true;
                }
                else {
                    check--;
                }
            }
        }
        if (!pass) {
            if (check != 0) {
                cout << "NO" << '\n';
            } else {
                cout << "YES" << '\n';
            }
        }
    }
}