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
    f[3] = 5;
    f[4] = 10;

    g[1] = 1;
    g[2] = 2;
    g[3] = 4;
    g[4] = 9;

    h[1] = 1;
    h[2] = 2;
    h[3] = 4;
    h[4] = 9;

    // RECURRENCE :

    for(ll i = 5; i <= n; i++){
        f[i] = f[i-1] + g[i-2] + h[i-2] + f[i-3] + g[i-4] + h[i-4];
        g[i] = g[i-1] + f[i-1];
        h[i] = h[i-1] + f[i-1];
    }


    // ANSWER : the answer is f(n) because we have to exactly fill the 2*N grid

    cout << f[n];

    return 0;
}

/*

a --> INPUT : 8 OUPUT : 227
b --> INPUT : 10 OUTPUT : 1071
c --> INPUT : 12 OUTPUT : 5038

*/
