#include <iostream>
#include <vector>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f3f

int main() {

    ll n;
    cin >> n;

    ll ans = -INF;

    vector<ll> dp(n+5);
    ll x;
    cin >> x;
    dp[0] = x;

    for(ll i = 1; i < n; i++){
        ll x;
        cin >> x;
        dp[i] = max(x,dp[i-1]+x);
        ans = max(ans,dp[i]);

    }

    cout << ans;

    return 0;
}

/*

a --> INPUT :

15
-1 3 -2 2 -2 1 -1 2 -4 2 -1 3 -2 1 -1

a --> OUTPUT

4

b --> INPUT :

25
-2 4 -3 3 -2 1 -2 2 -3 3 -1 1 -2 1 -2 4 -3 2 -1 2 -3 2 -2 3 -3

b --> OUTPUT :

4

c --> INPUT :

30
-1 4 -4 4 -3 3 -4 2 -2 4 -3 1 -4 4 -3 4 -3 2 -1 1 -4 5 -5 3 1 -1 -3 3 -2 5

c --> OUTPUT :

6

*/
