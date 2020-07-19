#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int N;
vector<ll> nv;
vector<ll> pv;
ll sum = 0;
ll zero = 0;
ll one = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N ;i++) {
		ll tmp;
		cin >> tmp;
		if (tmp == 0) {
			zero++;
		}
		else if (tmp == 1) {
			one++;
		}
		else if (tmp < 0) {
			nv.push_back(tmp);
		}
		else if (tmp > 1) {
			pv.push_back(tmp);
		}
	}
	sort(nv.begin(), nv.end());
	sort(pv.begin(), pv.end());
	ll nsum = 0;
	ll psum = 0;
	ll tmp = 0;
	if (nv.size() % 2 != 0) {
		if (zero == 0 ) {
			nsum += nv[nv.size()-1];
		}
		nv.pop_back();
	}
	for (int i = 0; i < nv.size(); i++) {
		if (tmp == 0) {
			tmp = nv[i];
		}
		else {
			nsum += tmp * nv[i];
			tmp = 0;
		}
	}
	tmp = 0;
	int size = pv.size();
	if (size % 2 != 0) {
		psum += pv[0];
		vector<ll>::iterator myi = pv.begin();
		pv.erase(myi);
	}
	size = pv.size();
	for (int i = size-1; i > 0; i -=2) {
		psum += pv[i]*pv[i-1];
	}
	sum = 0;
	sum = psum + nsum + one;
	cout << sum << '\n';
}