#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 13371337
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)
#define N 200005

int main() {

    ll n,k;
    cin in n in k;

    vi dp0(n+5);
    vi dp(n+5);

    // dp0[i] = number of k-bounded good lists of length i and ending the list with 0
    // dp[i] = number of k-bounded good lists of length i

    // base case :

    dp0[0] = 0;
    dp[0] = 1;

    dp0[1] = 1;
    dp[1] = k+1;

    // recurrence relation :

    fo(i,2,n){

        dp0[i] = dp[i-1] - dp0[i-2];
        dp[i] = dp[i-1]*k + dp0[i];
    }

    // answer :

    cout out dp[n];

    return 0;
}

