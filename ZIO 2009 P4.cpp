#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define INF 0x3f3f3f3f3f

int main() {

    fast;

    ll n,m;
    cin >> n >> m;

    vector<vector<ll>> grid(n+5 , vector<ll>(m+5));
    vector<vector<ll>> column(n+5 ,vector<ll>(m+5));
    vector<vector<ll>> row(n+5 , vector<ll>(m+5));

    for(ll i = 0; i <= n-1; i++){
        for(ll j = 0; j <= m-1; j++){
            cin >> grid[i][j];

            if(i == 0) column[i][j] = grid[i][j];
            else column[i][j] = column[i-1][j] + grid[i][j];

            if(j == 0) row[i][j] = grid[i][j];
            else row[i][j] = row[i][j-1] + grid[i][j];
        }
    }


    ll ans = -INF;

    for(ll i = 1; i <= n-1; i++){
        for(ll j = 1; j <= m-1; j++){

           ans = max(ans ,  row[0][j]+row[i][j]+column[i][0] + column[i][j] - grid[0][0] - grid[0][j] - grid[i][0] - grid[i][j] );

        }
    }

    cout << ans;

    return 0;
}

/*

a --> INPUT :

6 6
−1 1 −7 6 −1 5
3 −2 4 −4 1 −7
−2 4 −3 7 −1 1
1 −3 6 −1 2 −1
−3 1 −1 2 −2 1
5 −3 1 −4 1 −1

a --> OUTPUT

7

b --> INPUT :

6 6
−4 7 −5 7 −6 7
3 −4 3 −4 7 −2
−7 7 −4 5 −4 6
2 −7 6 −3 3 −5
−3 3 −2 5 −3 7
6 −6 5 −3 5 −3

b --> OUTPUT :

11

c --> INPUT :

6 6
−12 1 −7 9 −5 5
2 −9 3 −6 11 −7
−4 12 −10 12 −11 5
3 −1 3 −1 12 −9
−8 1 −11 3 −3 5
7 −3 9 −5 11 −5

c --> OUTPUT :

7

*/
