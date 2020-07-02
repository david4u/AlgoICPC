#include <iostream>

using namespace std;

string input;
bool check;
int main() {
    cin >> input;
    int count = 0;
    int answer = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '(') {
            count++;
        }
        if (input[i] == ')' && input[i-1] == '(') {
            answer += --count;
        }
        if (input[i] == ')' && input[i-1] == ')') {
            answer += 1;
            count--;
        }
    }
    cout << answer << '\n';
}