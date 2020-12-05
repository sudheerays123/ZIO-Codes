#include <iostream>
#include <vector>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f3f

int main() {

    ll n;
    cin >> n;

    vector<ll> a(n+5);
    vector<ll> one(n+5);
    vector<ll> zero(n+5);

    for(ll i = 0; i < n; i++) {

        cin >> a[i];
        if(i == 0 && a[i] == 1) {
            one[0] = 1;
            zero[0] = 0;
        }
        else if(i == 0) {
            one[0] = 0;
            zero[0] = 1;
        }

        if(i != 0 && a[i] == 1) {
            one[i] = one[i-1]+1;
            zero[i] = zero[i-1];
        }
        else if(i != 0 && a[i] == 0) {
            one[i] = one[i-1];
            zero[i] = zero[i-1]+1;
        }
    }

    vector<ll> dp(n+5);

    // Optimal Subproblem :

    // dp[i] = number of partitions possible ( into heavy sublists ) from 1 to i

    // Base case :

    if(a[0] == 1 && a[1] == 1){
        dp[0] = 1;
        dp[1] = 2;
    }
    if(a[0] == 1 && a[1] == 0){
        dp[0] = 1;
        dp[1] = 1;
    }
    if(a[0] == 0 && a[1] == 1){
        dp[0] = 0;
        dp[1] = 1;
    }
    if(a[0] == 0 && a[1] == 0){
        dp[0] = 0;
        dp[1] = 0;
    }

    // Recurrence :

    for(ll i = 2; i < n; i++){
        for(ll j = 0; j < i; j++){
            if(j == 0){
                if(one[i] >= zero[i]){
                    dp[i]++;
                }
            }
            else{
                if(one[i]-one[j-1] >= zero[i]-zero[j-1]){
                    dp[i] += dp[j-1];
                }
            }
        }

        if(a[i] == 1 && one[i-1] >= zero[i-1]) {
            dp[i] += dp[i-1];
        }
    }

    // Output :

    cout << dp[n-1];
    
    return 0;
}

/*

a --> INPUT :

8
0 1 1 0 0 1 1 1

a --> OUTPUT

20

b --> INPUT :

9
1 1 0 0 1 0 0 1 1

b --> OUTPUT :

16

c --> INPUT :

9
1 0 1 0 1 1 0 1 1

c --> OUTPUT :

96

*/
