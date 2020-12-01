#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f3f

vector<ll> dist(105,INF);
vector<pair<ll,ll>> adj[105];

void dijkstra(ll s){

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
            ll b = u.first;
            ll w = u.second;

            if(dist[a]+w < dist[b]){
                dist[b] = dist[a]+w;
                q.push({-dist[b],b});
            }
        }
    }
}

int main() {

    ll n,m;
    cin >> n >> m;

    for(ll i = 0; i < m; i++){

        ll u,v,speed,length;
        cin >> u >> v >> speed >> length;

        if(speed > 50 ) speed = 50;

        ll energy = length * (60 - speed);

        adj[u].push_back(make_pair(v,energy));

    }

    dijkstra(1);

    cout << dist[n];

    return 0;
}

/*

a --> INPUT :

7 9
1 2 60 15
1 3 40 10
1 4 20 5
2 5 40 20
3 5 60 30
3 6 30 10
4 6 20 5
5 7 30 10
6 7 30 10

a --> OUTPUT

700

b --> INPUT :

9 12
1 2 50 15
1 3 40 25
2 4 40 30
2 5 50 25
3 5 50 20
3 6 40 10
4 7 30 10
5 7 60 10
5 8 40 5
6 8 40 20
7 9 40 10
8 9 20 20

b --> OUTPUT :

700

c --> INPUT :

11 16
1 2 60 10
1 3 30 20
2 4 50 20
2 5 60 10
3 5 50 10
3 6 40 10
4 7 30 10
4 8 50 30
5 8 60 30
5 9 40 20
6 9 40 20
6 10 50 40
7 11 40 20
8 11 20 10
9 11 40 20
10 11 30 10

c --> OUTPUT :

900

*/
