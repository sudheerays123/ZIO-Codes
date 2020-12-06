#include <iostream>
#include <vector>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f3f


int main() {

    ll n;
    cin >> n;

    vector<vector<ll>> a(n+5,vector<ll>(2));
    vector<ll> dp(n+5);

    for(ll i = 0; i < n; i++) cin >> a[i][0];

    for(ll i = 0; i < n; i++) {
        char x;

        cin >> x;

        if(x == 'R') a[i][1] = 0;
        if(x == 'G') a[i][1] = 1;
        if(x == 'B') a[i][1] = 2;

    }

    ll redmax = -INF , greenmax = -INF , bluemax = -INF;

    dp[0] = a[0][0]*3;

    if(a[0][1] == 0) redmax = dp[0];
    if(a[0][1] == 1) greenmax = dp[0];
    if(a[0][1] == 2) bluemax = dp[0];

    for(ll i = 1; i < n; i++){

        dp[i] = a[i][0]*3;

        if(a[i][1] == 0) {

            dp[i] = max(dp[i],redmax + a[i][0]);
            dp[i] = max(dp[i],max(bluemax,greenmax)+3*a[i][0]);

            redmax = max(redmax , dp[i]);

        }

        if(a[i][1] == 1) {

            dp[i] = max(dp[i],greenmax + a[i][0]);
            dp[i] = max(dp[i],max(bluemax,redmax)+3*a[i][0]);

            greenmax = max(greenmax , dp[i]);

        }

        if(a[i][1] == 2) {

            dp[i] = max(dp[i],bluemax + a[i][0]);
            dp[i] = max(dp[i],max(redmax,greenmax)+3*a[i][0]);

            bluemax = max(bluemax , dp[i]);
        }

    }

    cout << max(redmax,max(bluemax,greenmax));

    return 0;
}

/*

a --> INPUT :

9
5 8 20 -2 10 -8 -2 13 -8
R R R G R B B B R

a --> OUTPUT

123

b --> INPUT :

13
8 9 -5 2 4 -6 2 1 -3 -3 7 9 1
R R R R B B B B G G B B B

b --> OUTPUT :

72

c --> INPUT :

14
-1 -3 4 -5 7 10 -8 6 7 4 -3 2 9 -4
G G B R G B B B B B R R R G
 
c --> OUTPUT :

107

*/
