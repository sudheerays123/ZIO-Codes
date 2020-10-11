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

    cout << max(dp[n-1][0] , max(dp[n-1][1] , dp[n-2][1]));

    return 0;
}
