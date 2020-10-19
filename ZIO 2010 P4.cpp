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

/*

a --> INPUT :

9 3
1 12 17 20 26 40 50 59 69

a --> OUTPUT :

20

b --> INPUT :

15 5
8 11 13 17 27 40 54 67 79 95 103 107 113 124 137

b --> OUTPUT :

33

c --> INPUT :

20 6
5 22 40 58 70 76 87 107 127 136 150 169 186 206 213 220 227 235 254 272

c --> OUTPUT :

63

*/
