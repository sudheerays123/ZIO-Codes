#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f3f

int main() {

    ll n; // number of tiles

    cin >> n;

    vector<vector<ll>> tile(n+5 , vector<ll>(2));

    for(ll i = 0; i < n; i++) {
        cin >> tile[i][0] >> tile[i][1];
        if(tile[i][0] > tile[i][1]) swap(tile[i][0] , tile[i][1]);
    }

    vector<vector<ll>> dp(n+5 , vector<ll>(2));

    // DP[i][0] = maximum score possible if we jump to this value ( smaller )
    // DP[i][1] = maximum score possible if we jump to this value ( larger )

    // BASE CASE :

    dp[0][0] = tile[0][0];
    dp[0][1] = tile[0][1];
    dp[1][0] = tile[1][0] + tile[0][0];
    dp[1][1] = tile[1][1] + tile[0][0];

    // RECURRENCE :

    for(ll i = 2; i < n; i++){
        dp[i][0] = tile[i][0] + max( dp[i-1][0] , dp[i-2][1]);
        dp[i][1] = tile[i][1] + max( dp[i-1][0] , dp[i-2][1]);
    }

    // ANSWER :

    cout << max(dp[n-2][1] , max(dp[n-1][0] , dp[n-1][1]));

    return 0;
}

/*

a --> INPUT :

10
2 -2
-3 -2
-3 -1
1 2
1 -5
4 -2
-4 -5
4 -5
-2 -5
5 4

a --> OUTPUT

14

b --> INPUT :

12
1 -1
-3 1
4 -1
-3 4
1 2
4 3
3 -4
4 1
4 2
-1 1
-2 -1
-3 -4

b --> OUTPUT :

15

c --> INPUT :

14
-1 -5
1 -1
-3 5
-5 2
-2 -4
4 -4
-2 5
-3 -2
-3 4
3 -5
3 -5
-1 5
1 -1
3 4

c --> OUTPUT :

17

*/
