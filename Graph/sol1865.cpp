#include <iostream>
#include <vector>

using namespace std;

int TC, N, M, W;

struct load {
	int start;
	int end;
	int cost;
};

long long dist[501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> TC;

	while(TC--) {
		cin >> N >> M >> W;

		for (int i = 1; i <= 500; i++) {
			dist[i] = 987654321;
		}
		vector<load> edges;
		bool answer = false;

		for (int i = 1; i <= M; i++) {
			load newone;
			cin >> newone.start >> newone.end >> newone.cost;
			int tmp = newone.start;
			edges.push_back(newone);
			newone.start = newone.end;
			newone.end = tmp;
			edges.push_back(newone);
		}

		for (int i = 1;  i<= W; i++) {
			load newone;
			cin >> newone.start >> newone.end >> newone.cost;
			newone.cost *= -1;
			edges.push_back(newone);
		}


		// bellman-ford

		dist[1] = 0;
		for (int i = 1; i<= N-1; i++) {
			for (int j = 1; j <= edges.size(); j++) {
				int from = edges[j-1].start;
				int to = edges[j-1].end;
				int cost = edges[j-1].cost;

				if (dist[to] > dist[from] + cost) {
					dist[to] = dist[from] + cost;
				}
			}
		}

		for (int i = 1; i <= edges.size(); i++) {
			int from = edges[i-1].start;
			int to = edges[i-1].end;
			int cost = edges[i-1].cost;

			if (dist[to] > dist[from] + cost) {
				answer = true;
			}
		}

		if (answer ) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	
}