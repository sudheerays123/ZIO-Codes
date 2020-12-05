#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f3f

int main() {

    ll n,k;
    cin >> n >> k;

    vector<ll> a(n+5);

    vector<ll> zero(0);
    vector<ll> one(0);
    vector<ll> two(0);
    vector<ll> three(0);
    vector<ll> four(0);

    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        if(i%5 == 0) zero.push_back(a[i]);
        if(i%5 == 1) one.push_back(a[i]);
        if(i%5 == 2) two.push_back(a[i]);
        if(i%5 == 3) three.push_back(a[i]);
        if(i%5 == 4) four.push_back(a[i]);
    }

    sort(zero.rbegin(),zero.rend());
    sort(one.rbegin(),one.rend());
    sort(two.rbegin(),two.rend());
    sort(three.rbegin(),three.rend());
    sort(four.rbegin(),four.rend());

    vector<ll> maxi(0);

    maxi.push_back(zero[0]);
    maxi.push_back(one[0]);
    maxi.push_back(two[0]);
    maxi.push_back(three[0]);
    maxi.push_back(four[0]);

    sort(maxi.rbegin(),maxi.rend());

    ll ans = 0;

    for(ll i = 0; i < min(5ll,k); i++) ans += maxi[i];

    cout << ans;

    return 0;
}

/*

a --> INPUT :

21 6
3 8 21 13 15 4 10 17 6 12 1 11 20 14 16 5 18 19 7 9 2

a --> OUTPUT

74

b --> INPUT :

23 4
4 23 15 7 9 3 20 19 8 10 1 22 16 6 14 5 21 17 11 12 2 18 13

b --> OUTPUT :

67

c --> INPUT :

23 4
17 5 21 12 1 11 10 19 9 6 18 8 23 14 2 15 3 22 13 4 16 7 20

c --> OUTPUT :

65

*/
