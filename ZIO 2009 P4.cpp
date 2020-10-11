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
