#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mp make_pair
#define INF 0x3f3f3f3f3f

int main(){

   ll n ,m ;
   cin >> n >> m;

   vector<vector<ll>> grid(n+5,vector<ll>(m+5));
   vector<vector<ll>> dijkstra(n+5,vector<ll>(m+5,INF));
   priority_queue<pair<ll,pair<ll,ll>>> q; // first number will hold the dijkstra[i][j] , and the second pair will hold the coordinates i.e i,j

   for(ll i = 0; i < n; i++){
       for(ll j = 0; j < m; j++){
           cin >> grid[i][j];
       }
   }

   dijkstra[0][0] = grid[0][0];
   q.push(mp(-dijkstra[0][0],mp(0,0)));

   while(!q.empty()){

       pair<ll,pair<ll,ll>> a = q.top();
       q.pop();

       ll x = a.second.first;
       ll y = a.second.second; 
       ll w = abs(a.first) // taking absolute value because we have pushed negative value

       if(x != n-1 && dijkstra[x+1][y] == INF){

           dijkstra[x+1][y] = w + grid[x+1][y];;
           q.push(mp(-dijkstra[x+1][y],mp(x+1,y))); // priority queue sorts the elements in it in descending order but we need the smallest element first therefore we push negative value

       }

       if(x != 0 && dijkstra[x-1][y] == INF){

           dijkstra[x-1][y] = w + grid[x-1][y];
           q.push(mp(-dijkstra[x-1][y],mp(x-1,y))); // priority queue sorts the elements in it in descending order but we need the smallest element first therefore we push negative value

       }

       if(y != m-1 && dijkstra[x][y+1] == INF){

           dijkstra[x][y+1] = w + grid[x][y+1];
           q.push(mp(-dijkstra[x][y+1],mp(x,y+1))); // priority queue sorts the elements in it in descending order but we need the smallest element first therefore we push negative value

       }

       if(y != 0 && dijkstra[x][y-1] == INF){

           dijkstra[x][y-1] = w + grid[x][y-1];
           q.push(mp(-dijkstra[x][y-1],mp(x,y-1))); // priority queue sorts the elements in it in descending order but we need the smallest element first therefore we push negative value

       }
   }

   cout << dijkstra[n-1][m-1];

   return 0;
}

/*

a --> INPUT :

5 6
8 11 4 6 14 14
27 26 21 5 19 11
9 2 4 5 18 23
12 10 15 28 29 7
20 2 8 16 3 17

a --> OUTPUT

101

b --> INPUT :

4 8
4 2 3 3 2 5 4 5
1 3 5 5 5 5 5 5
5 4 4 1 4 5 3 3
1 3 2 3 5 4 5 5

b --> OUTPUT :

37

c --> INPUT :

5 6
15 21 29 15 28 39
27 37 34 21 17 30
28 14 30 13 38 34
25 13 31 38 23 40
16 21 20 28 14 4

c --> OUTPUT :

184

*/
