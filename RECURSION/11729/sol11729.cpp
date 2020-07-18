#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> q;

void hanoi(int x, int from, int to) {
    int aux = 6-from-to;
    if( x == 1) {
		q.push_back({from, to});
		return ;
	}
    hanoi(x-1, from, aux);
   	q.push_back({from, to});
    hanoi(x-1, aux, to);
}

int  main() {
    cin >> N;
	hanoi(N, 1, 3);
	cout << q.size() << '\n';
	int size = q.size();
	for (int i = 0; i < size; i++) {
		cout << q[i].first << " " << q[i].second << '\n';
	}
    
    
}