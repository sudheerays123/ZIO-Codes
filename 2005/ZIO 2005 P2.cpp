#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f3f

ll n;
vector<ll> adj[105];

ll dijkstra(ll s){

    vector<ll> dist(105,INF);
    vector<bool> visited(105,false);
    priority_queue<pair<ll,ll>> q;

    q.push({0,s});
    dist[s] = 0;

    while(!q.empty()){

        ll a = q.top().second;
        q.pop();
        if(visited[a]) continue;

        visited[a] = true;
        for(auto u : adj[a]){

            if(dist[a]+1 < dist[u]){
                dist[u] = dist[a]+1;
                q.push({-dist[u],u});
            }
        }
    }

    ll maxi = -INF;

    for(ll i = 1; i <= n; i++) maxi = max(maxi,dist[i]);

    return maxi;
}

int main() {

    cin >> n;

    for(ll i = 0; i < n-1; i++){

        ll u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll ans , mini = INF;

    for(ll i = 1; i <= n; i++){
        ll x = dijkstra(i);

        if(x < mini){
            mini = x;
            ans = i;
        }
    }

    cout << ans;

    return 0;
}

/*

a --> INPUT :

15
5 4
4 2
2 3
2 1
1 6
6 7
6 8
7 9
8 13
8 14
9 10
9 11
11 12
14 15

a --> OUTPUT

6

b --> INPUT :

20
1 2
1 3
1 15
2 4
2 5
3 8
3 7
3 6
4 10
4 9
5 11
6 13
6 14
13 12
15 16
16 17
17 18
18 19
19 20

b --> OUTPUT :

15

c --> INPUT :

24
1 2
1 3
1 4
2 24
4 5
5 6
6 7
6 18
6 19
7 8
7 9
7 10
10 14
11 13
12 13
13 14
14 15
15 16
15 17
18 20
18 21
19 23
19 22

c --> OUTPUT :

6

*/
