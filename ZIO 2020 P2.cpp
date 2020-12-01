#include <iostream>
using namespace std;
#define ll long long int
#define INF LLONG_MAX

int main() {

    ll n;
    cin >> n;

    ll x = log2(n);
    ll ans = -INF;

    for(ll i = 0; i <= x; i++){

        ll remaining = n - pow(2,i);
        ll r = log2(remaining);

        ans = max(ans,r+i);
    }

    cout << ans;

    return 0;
}

/*

a --> INPUT :

9

a --> OUTPUT :

4

b --> INPUT :

58

b --> OUTPUT :

9

c --> INPUT :

2000

c --> OUTPUT :

19

*/
