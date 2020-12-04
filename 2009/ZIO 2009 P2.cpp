#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f3f

int main() {

    ll n,m;
    cin >> n >> m;

    vector<vector<ll>> grid(n+5,vector<ll>(m+5));
    vector<vector<ll>> dp(n+5,vector<ll>(m+5));

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    ll ans = -INF;

    dp[0][0] = grid[0][0];

    for( ll i = 1; i < n; i++ ){
        dp[i][0] = max(grid[i][0],grid[i][0]+dp[i-1][0]);
    }
    for( ll j = 1; j < m; j++ ){
        dp[0][j] = max(grid[0][j],grid[0][j]+dp[0][j-1]);
    }

    for(ll i = 1; i < n; i++){
        for(ll j = 1; j < m; j++){
            dp[i][j] = max(grid[i][j],max(dp[i-1][j],dp[i][j-1])+grid[i][j]);
            if(i == n-1 || j == m-1 ) ans = max(ans,dp[i][j]);
        }
    }

    cout << ans;

    return 0;
}

/*

a --> INPUT :

5 5
-2 1 -3 4 -4
12 -16 10 -12 6
-16 13 -14 7 -4
7 -4 16 -15 10
-7 16 -9 13 -16

a --> OUTPUT

29

b --> INPUT :

5 5
-4 4 -6 5 -7
5 -6 5 -5 5
-7 5 -4 7 -7
6 -4 6 -5 5
-5 6 -5 6 -4

b --> OUTPUT :

9

c --> INPUT :

6 6
-6 5 -4 7 -5 11
7 -6 7 -10 10 -4
-6 10 -5 4 -6 7
8 -7 10 -5 5 -10
-9 11 -7 11 -7 4
8 -10 5 -9 5 -6

c --> OUTPUT :

20

*/
