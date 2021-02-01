#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 7
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef;
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)

vi adj[15];

ll longestPath(){

    queue<ll> nodep;
    vi dist(15,INF);
    vi indegree(15,0);

    fo(i,0,9){
        for(auto j : adj[i]){
            indegree[j]++;
        }
    }

    fo(i,0,9){
        if(indegree[i] == 0){
            nodep.push(i);
            dist[i] = 1;
        }
    }

    while(!nodep.empty()){

        ll a = nodep.front();
        nodep.pop();

        for(auto k : adj[a]){

            indegree[k]--;
            if(indegree[k] == 0) {
                nodep.push(k);
                mmin(dist[k],dist[a]+1);
            }

        }
    }

    ll minsemester = -INF;
    fo(i,0,9) if(dist[i] != INF ) mmax(minsemester,dist[i]);

    return minsemester;

}

int main() {

    ll n;
    cin in n;

    fo(i,0,n-1){

        ll x,y;
        string s;

        cin in x in s in y;

        x--;y--;

        if(s == "after"){
            adj[y].pb(x);
        }
        else{
            adj[x].pb(y);
        }
    }

    cout out longestPath();

    return 0;
}

/*

a --> INPUT :

15
4 before 5
2 after 5
4 before 2
6 after 7
1 after 2
2 before 3
3 after 4
7 before 2
1 before 8
10 after 2
3 before 1
1 after 6
10 before 9
8 before 9
9 after 1

a --> OUTPUT :

7

b --> INPUT :

6 before 9
3 after 8
2 after 6
1 before 5
3 after 2
4 before 7
2 after 9
8 before 1
4 after 3
10 before 4
9 before 8
2 before 10
1 before 4
7 after 1
4 after 8
3 after 9

b --> OUTPUT :

6

c --> INPUT :

4 before 6
9 before 8
2 after 4
3 after 5
7 after 3
5 before 4
9 after 3
10 after 6
2 before 1
7 before 1
3 before 10
1 after 8
2 before 10

c --> OUTPUT :

5

d --> INPUT :

4 before 10
3 after 4
2 after 1
10 after 7
3 before 2
4 before 1
3 after 9
5 before 6
8 after 1
2 before 6
9 before 8
5 after 2
10 before 8
6 before 7
8 after 5

d --> OUPUT :

8

*/
