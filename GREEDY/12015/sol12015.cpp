#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int s[1000001];
vector<int> ss;

int main() {
	cin >> N;
	for(int i = 0; i< N; i++) {
		cin >> s[i];
	}
	ss.push_back(s[0]);
	vector<int>::iterator myi;
	for (int i = 1; i < N; i++) {
		myi = lower_bound(ss.begin(), ss.end(), s[i]);
		if(myi == ss.end()) {
			ss.push_back(s[i]);
		}
		else {
			*myi = s[i];
		}
	}
	cout <<ss.size() << '\n';
}