#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){

    ll n;
    cin >> n;

    vector<ll> f(n+5);
    vector<ll> g(n+5);
    vector<ll> h(n+5);

    // DP :

    // F[i] = number of ways to put tiles which exactly ends at i;
    // G[i] = number of ways to put tiles which ends at i and has one extra tile at the bottom of the next column
    // H[i] = number of ways to put tiles which ends at i and has one extra tile at the top of the next column

    // BASE CASE :

    f[1] = 1;
    f[2] = 2;

    g[1] = 1;
    g[2] = 2;

    h[1] = 1;
    h[2] = 2;

    // RECURRENCE :

    for(ll i = 3; i <= n; i++){
        f[i] = f[i-1] + f[i-2] + g[i-2] + h[i-2];
        g[i] = g[i-1] + f[i-1];
        h[i] = h[i-1] + f[i-1];
    }


    // ANSWER : the answer is f(n) because we have to exactly fill the 2*N grid

    cout << f[n];

    return 0;
}
