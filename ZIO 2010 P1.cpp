#include <iostream>
#include <vector>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f3f

vector<bool> visited(105);
vector<ll> adj[105];
vector<ll> dp(105);

void dfs(ll s){

    if(visited[s]) return;
    visited[s] = true;

    ll product = 1;
    for(auto u : adj[s]){
        dfs(u);
        product *= dp[u];
    }

    dp[s] = product + 1;

}

int main() {

    ll n;
    cin >> n;

    for( ll i = 1; i < n; i++){

        ll parent,child;
        cin >> parent >> child;

        adj[parent].push_back(child);
    }

    dfs(1);

    cout << dp[1];

    return 0;
}

/*

a --> INPUT :

14
1 2
1 3
1 4
2 5
3 6
3 7
4 8
4 9
6 10
6 11
7 12
7 13
7 14

a --> OUTPUT

691

b --> INPUT :

16
1 2
1 3
2 4
2 5
3 6
3 7
5 8
5 9
6 10
6 11
6 12
6 13
7 14
12 15
13 16

b --> OUTPUT :

1233

c --> INPUT :

16
1 2
1 3
1 4
2 5
2 6
2 7
3 8
4 9
4 10
8 11
8 12
9 13
9 14
10 15
10 16

c --> OUTPUT :

1405

*/
