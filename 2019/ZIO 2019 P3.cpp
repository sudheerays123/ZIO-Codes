#include <iostream>
#include<vector>
using namespace std;
#define ll long long int

int main() {

    ll n;
    cin >> n;

    vector<ll> dp1(n+5);
    vector<ll> dp2(n+5);

    // OPTIMAL SUB-PROBLEM :

    // dp1[i] = Number of sequences which can be formed from the first i people excluding the adjacent ones.
    // dp2[i] = number of sequences which can be formed from the first i people excluding the adjacent ones and 1 .

    // BASE CASE :

    dp1[0] = 1; // choosing 1st person alone
    dp1[1] = 1; // choosing the 2nd person alone

    dp2[0] = 0; // can't choose anyone
    dp2[1] = 1; // choosing the 2nd person alone

    // RECURRENCE :

    for(ll i = 2; i < n-1; i++){

        // Computing dp1 :

        ll sum1 = 0;
        for(ll j = 0; j < i-1; j++ ) sum1 += dp1[j];
        dp1[i] = sum1;
        dp1[i]++;

        // Computing dp2 :

        ll sum2 = 0;
        for(ll j = 1; j < i-1; j++) sum2 += dp2[j];
        dp2[i] = sum2;
        dp2[i]++;

    }

    for(ll i = 1; i < n-2; i++) dp1[n-1] += dp2[i];
    dp1[n-1]++;

    // ANSWER :

    ll ans = 0;

    for(ll i = 0; i < n; i++) ans += dp1[i];

    cout << ans;

    return 0;
}

/*

a --> INPUT :

11

a --> OUTPUT :

198

b --> INPUT :

13

b --> OUTPUT :

520

c --> INPUT :

15

c --> OUTPUT :

1363

*/
