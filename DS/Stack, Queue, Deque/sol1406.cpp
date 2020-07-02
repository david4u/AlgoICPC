#include <iostream>
#include <list>

using namespace std;

int main() {
    string str, cmd;
    list<char> lt;
    int T;
    char tmp;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        lt.push_back(str[i]);
    }
    list<char>::iterator myi = lt.end();

    cin >> T;

    while (T--) {
        cin >> cmd;
        if (cmd == "L") {
            if (myi != lt.begin()) {
                myi--;
            }
        }
        if (cmd == "D") {
            if (myi != lt.end()) {
                myi++;
            }
        }
        if (cmd == "B") {
            if (myi != lt.begin()) {
                myi = lt.erase(--myi);
            }
        }
        if (cmd == "P") {
            cin >> cmd;
            lt.insert(myi, cmd[0]);
        }
    }
    for (myi = lt.begin(); myi != lt.end(); myi++) {
        cout << *myi;
    }
    cout << '\n';
}

