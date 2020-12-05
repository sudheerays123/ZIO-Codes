#include <iostream>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f3f

int main() {

    ll n,k,a,b,c;
    cin >> n >> k >> a >> b >> c;

    n -= k;
    a--;
    b--;
    c--;

    ll ans = INF;

    for(ll i = 0; i <= n/a; i++){
        for(ll j = 0; j <= n/b; j++){
            for(ll k = 0; k <= n/c; k++){
                if(i*a + j*b + c*k == n){
                    ans = min(ans,i+j+k);
                }
            }
        }
    }

    cout << ans;

    return 0;
}

/*

a --> INPUT :

114 23 7 12 16

a --> OUTPUT :

8

b --> INPUT :

76 9 7 15 16

b --> OUTPUT :

7

c --> INPUT :

138 10 9 12 26

c --> OUTPUT :

11

*/
