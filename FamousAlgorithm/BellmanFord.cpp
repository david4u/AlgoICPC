#include <iostream>
#include <vector>

using namespace std;

const int MAX_V = 100;
const int INF = 987654321;
int V;

vector<pair<int, int>> adjlst[MAX_V];

// 음수 사이클이 존재한다면 텅 빈 배열을 반환한다.
vector<int> bellmanFord(int src) {
	vector<int> upper(V, INF);
	upper[src] = 0;
	bool updated;
	
	// v번 순회한다.
	for (int iter = 0; iter < V; iter++) {
		updated = false;
		for (int here = 0; here < V; here++) {
			for (int i = 0; i < adjlst[here].size(); i++) {
				int there = adjlst[here][i].first;
				int cost = adjlst[here][i].second;
				
				if (upper[there] > upper[here] + cost) {
					upper[there] = upper[here] + cost;
					updated = true;
				}
			}
		}
		if (!updated) break;
	}
	if (updated) upper.clear();
	return upper;
}