#include <iostream>
#include <cstring>

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
		for (int i = next; i != x; i = pointOf[i]) {
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
		count = 0;
		memset(visit, false, sizeof(visit));
		memset(finish, false, sizeof(finish));
		for (int i = 1 ; i <= N; i++) {
			cin >> pointOf[i];
		}
		for (int i = 1; i <= N; i++) {
			if (visit[i] == false) {
				DFS(i);
			}
		}
		cout << N - count << '\n';
	}
	return 0;
}