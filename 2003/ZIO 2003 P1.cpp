#include <iostream>
#include <vector>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f3f

int main() {

    ll n;
    cin >> n;

    vector<ll> a(n+5);
    for(ll i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(),a.begin()+n);

    ll ans = -INF;

    for(ll i = 0; i < n/2; i++) ans = max(ans,a[i]+a[n-i-1]);

    cout << ans;

    return 0;
}

/*

a --> INPUT :

10
103 24 77 65 12 108 69 25 66 83

a --> OUTPUT

142

b --> INPUT :

10
83 112 -16 72 161 75 152 -23 77 247

b --> OUTPUT :

224

c --> INPUT :

10
19 81 2 41 61 59 28 69 76 88

c --> OUTPUT :

120

*/
