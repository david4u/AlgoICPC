#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
#include <climits>

using namespace std;

const int mod=1000000000LL;

int dp[201][201];

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin >> n >> k;

    dp[0][0]=1;
    for(int i=1;i<=k;i++){
        for(int t=0;t<=n;t++){
            for(int j=0;j<=t;j++){
                dp[i][t] += dp[i-1][j];
                dp[i][t] %= mod;
            }
        }
    }

    cout << dp[k][n] << '\n';

    return 0;
}