#include <iostream>

using namespace std;

int pointOf[100001];
bool visit[100001];
bool finish[100001];
int K;
int N;
int count;

void DFS(int x) {
	visit[x] = true;

	int next = pointOf[x];
	if (visit[next] == false) {
		DFS(next);
	} else if (finish[next] == false) {
		for (int i = next; i != x; i++) {
			count++;
		}
		count++;
	}
	finish[x] = true;
}

int main() {
	cin >> K;
	while(K--) {
		cin >> N;
		for (int i = 1 ; i <= N; i++) {
			cin >> pointOf[i];
		}
		for (int i = 1; i <= N; i++) {
			if (visit[i] == false) {
				DFS(i);
			}
		}
        for (int i = 1; i <= N; i++) {
			visit[i] = false;
			pointOf[i] = 0;
			finish[i] = false;
		}
		cout << N - count << '\n';
        count = 0;
	}
	return 0;
}