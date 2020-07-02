#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;

int main() {
    int T;
    int tmp;
    string tcmd;
    string cmd;
    int count = 0;
    cin >> T;
    while (T--) {
        cin >> cmd;
        if (cmd == "push_back") {
            cin >> tmp;
            dq.push_back(tmp);
            count++;
        }
        else if (cmd == "push_front") {
            cin >> tmp;
            dq.push_front(tmp);
            count++;
        }
        else if (cmd == "pop_front") {
            if (count == 0) {
                cout << -1 << '\n';
            } else {
                tmp = dq.front();
                cout << tmp << '\n';
                dq.pop_front();
                count--;
            }
        }
        else if (cmd == "pop_back") {
            if (count == 0) {
                cout << -1 << '\n';
            } else {
                tmp = dq.back();
                cout << tmp << '\n';
                dq.pop_back();
                count--;
            }
        }
        else if (cmd == "size") {
            cout << count << '\n';
        }
        else if (cmd == "empty") {
            if (count == 0) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (cmd == "front") {
            if (count == 0) {
                cout << -1 << '\n';
            } else {
                cout << dq.front() << '\n';
            }
        }
        else if (cmd == "back") {
            if (count == 0) {
                cout << -1 << '\n';
            } else {
                cout << dq.back() << '\n';
            }
        }
    }
}