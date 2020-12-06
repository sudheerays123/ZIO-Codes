#include <iostream>
#include <vector>
using namespace std;
#define ll long long int

int main() {

    ll n;
    cin >> n;

    vector<vector<char>> grid(3,vector<char>(n+5));

    for(ll i = 0; i < 3; i++){
        for(ll j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<ll>> dp0(3,vector<ll>(n+5));
    vector<vector<ll>> dp1(3,vector<ll>(n+5));

    for(ll i = 0; i < 3; i++){

        if(grid[i][0] == 'R'){
            dp0[i][0] = 0;
            dp1[i][0] = 1;
        }

        else{
            dp0[i][0] = 1;
            dp1[i][0] = 0;
        }
    }

    for(ll j = 1; j < n; j++ ){
        for(ll i = 0; i < 3; i++){
            if(grid[i][j] == 'R'){
                if(i == 0){
                    dp0[i][j] = dp1[1][j-1] + dp1[2][j-1];
                    dp1[i][j] = dp0[1][j-1] + dp0[2][j-1];
                }
                else if(i == 1){
                    dp0[i][j] = dp1[0][j-1] + dp1[2][j-1];
                    dp1[i][j] = dp0[0][j-1] + dp0[2][j-1];
                }
                else if(i == 2){
                    dp0[i][j] = dp1[0][j-1] + dp1[1][j-1];
                    dp1[i][j] = dp0[0][j-1] + dp0[1][j-1];
                }
            }
            else{
                if(i == 0){
                    dp1[i][j] = dp1[1][j-1] + dp1[2][j-1];
                    dp0[i][j] = dp0[1][j-1] + dp0[2][j-1];
                }
                else if(i == 1){
                    dp1[i][j] = dp1[0][j-1] + dp1[2][j-1];
                    dp0[i][j] = dp0[0][j-1] + dp0[2][j-1];
                }
                else if(i == 2){
                    dp1[i][j] = dp1[0][j-1] + dp1[1][j-1];
                    dp0[i][j] = dp0[0][j-1] + dp0[1][j-1];
                }
            }
        }
    }

    cout << dp0[0][n-1] + dp0[1][n-1] + dp0[2][n-1];

    return 0;
}

/*

a --> INPUT :

6
R R R R G B
R G R B B G
G G G R R G

a --> OUTPUT :

40

b --> INPUT :

6
G G R G B G
G R R B G R
B B G G R R

b --> OUTPUT :

52

c --> INPUT :

7
R G R B B R B
G R R G R G R
G G G R G R R

c --> OUTPUT :

96

 */
