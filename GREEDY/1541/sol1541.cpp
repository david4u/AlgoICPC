#include <iostream>
#include <cstring>

using namespace std;

string problem;
int number[5];
int digit = 0;
int numbers[10000];
int now = 0;
int cnt = 0;

int main() {
	cin >> problem;
	memset(numbers, 0, sizeof(numbers));
	for (int i = 0; i < problem.size(); i++) {
		digit = 0;
		if (problem[i] == '-') {

		}
		else if (problem[i] == '+') {

		}
		else {
			while (problem[i] != '-' || problem[i] != '+') {
				number[digit] = problem[i];
				digit++;
				i++;
			}
			int data = 0;
			for (int j = 0; j < digit; j++) {
				data += number[j] * (digit-j);
			}
			numbers[cnt++] = data;
		}
	}
	for (int i = 0; i < cnt; i++) {
		cout << numbers[i] << '\n';
	}
}