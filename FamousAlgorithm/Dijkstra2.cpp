#include <vector>

using namespace std;

const int INF = 987654321;
const int MAX_V = 100;
int V;

int min(int x, int y) {
	return x < y ? x : y;
}

vector<pair<int, int>> adj[MAX_V];
vector<int> dijkstra2(int src) {
	vector<int> dist(V, INF);
	vector<bool> visited(V, false);
	dist[src] = 0;
	visited[src] = true;
	while(true) {
		int closest = INF, here;
		for (int i = 0; i < V; i++) {
			if (dist[i] < closest && !visited[i]) {
				here = i;
				closest = dist[i];
			}
		}
		if (closest == INF) {
			break;
		}
		visited[here] = true;
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			if (visited[there]) continue;
			int nextDist = dist[here] + adj[here][i].second;
			dist[there] = min(dist[there], nextDist);
		}
	}
	return dist;
}
