#include <iostream>
#include <vector>
using namespace std;
#define ll long long int

int main() {

    ll n;
    cin >> n;

    vector<ll> dp(n+5);

    // OPTIMAL SUBPROBLEM :

    // dp[i] = number of ways we can create subsequences and having ith element at the end of the subsequence only

    // BASE CASE :

    dp[1] = 1;
    dp[2] = 2;

    // RECURRENCE :

    for(ll i = 3; i <= n; i++){
        dp[i] = 1;
        for(ll j = 1; j < i; j++){
            if(i%j == 0) {
                dp[i] += dp[j];
            }
        }
    }

    // ANSWER :

    ll ans = 0;

    for(ll i = 1; i <= n; i++) ans += dp[i];

    cout << ans;

    return 0;
}
