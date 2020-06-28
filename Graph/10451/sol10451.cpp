#include <iostream>
#include <vector>

using namespace std;

int T;
int N;
int P[1001];
bool check[1001];
int ans[1000000];
vector<int> tests[1000000];

int solProblem() {
    bool more = true;
    int count = 0;
    int cur = 1;
    int next;
	
    while (more) {
        check[cur] = true;
        next = P[cur];
        while(next != cur) {
            check[next] = true;
            next = P[next];
        }
		count++;
        more = false;
        for (int k = 1; k <= N; k++) {
        	if (check[k] == false) {
            	cur = k;
            	more = true;
            	break;
        	}
    	}
    }
    return count;
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> tests[i][0];
        for ( int j = 1; j <= tests[i][0]; j++) {
            cin >> tests[i][j];
        }
    }
    for (int i = 0; i < T; i++) {
        N = tests[i][0];
        for (int j = 1; j <= N; j++) {
            P[j] = tests[i][j];
        }
        for (int j = 1; j <= N; j++) {
            check[j] = false;
        }
        ans[i] = solProblem();
    }
    for (int i = 0; i< T; i++) {
        cout << ans[i];
    }
    return 0;
}
