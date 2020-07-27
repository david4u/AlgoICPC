#include <iostream>

using namespace std;

const int MAX = 100001;

int inO[MAX], postO[MAX];
int idx[MAX];

void preO(int inf, int inl, int postf, int postl) {
	if (inf > inl || postf > postl) {
		return;
	}

	int root = postO[postl];
	cout << root << " ";

	preO(inf, idx[root] -1, postf, postf + (idx[root] - inf) -1);
	preO(idx[root] + 1, inl, postf + (idx[root] - inf), postl -1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> inO[i];
	}
	for (int i = 0 ;i < N; i++) {
		cin >> postO[i];
	}
	for (int i = 0; i < N; i++) {
		idx[inO[i]] = i;
	}

	preO(0, N-1, 0, N-1);
	cout << '\n';
	return 0;
}
