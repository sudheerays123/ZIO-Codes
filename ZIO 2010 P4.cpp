#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF LLONG_MAX

int main() {

    ll n,k;
    cin >> n >> k;

    vector<ll> a(n+5);
    for(ll i = 0; i < n; i++) cin >> a[i];

    vector<ll> diff(0);
    for(ll i = 1; i < n; i++){
        diff.push_back(a[i]-a[i-1]);
    }

    vector<vector<ll>> dp(n+5 , vector<ll>(k+5,INF));

    // DP[i][j] = minimum lenght of cable needed if we consider the first i offices and the k = j

    // BASE CASE :

    dp[0][1] = diff[0];
    for(ll i = 1; i < n-1; i++) dp[i][1] = min(dp[i-1][1] , diff[i]);

    // RECURRENCE :

    ll notPossible = 2;

    for(ll j = 2; j <= k; j++){
        for(ll i = notPossible; i < n-1; i++){
            dp[i][j] = min(dp[i-1][j] , diff[i]+dp[i-2][j-1]);
        }
        notPossible += 2;
    }

    // ANSWER :

    cout << dp[n-2][k];

    return 0;
}
