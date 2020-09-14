#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<vector<int>> result;

int N, M;

int main() {
	cin >> N >> M;
	for (int i = 1; i<= N; i++) {
		v.push_back(i);
	}
	do {
		vector<int> tmp;
		for (int i = 0; i < M; i++) {
			tmp.push_back(v[i]);
		}
		result.push_back(tmp);

	} while (next_permutation(v.begin(), v.end()));
	
	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < M; j++) {
			cout << result[i][j] << " " ;
		}
		cout << '\n';
	}
}