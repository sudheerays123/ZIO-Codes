#include <iostream>
#include <vector>
using namespace std;
#define ll long long int
#define INF LLONG_MAX

vector<vector<ll>> ways(10,vector<ll>(15,-1));
vector<ll> adj[10];

ll findAns(ll starting , ll length){

    if(length == 1) return 1;
    if(ways[starting][length] != -1 ) return ways[starting][length]%100;

    ll sum = 0;

    for(auto i : adj[starting]){
        sum += findAns(i,length-1);
        sum %= 100;
    }

    ways[starting][length] = sum;

    return ways[starting][length]%100;
}

int main() {

    ll start , length;
    cin >> start >> length;

    adj[1] = { 2 , 4 };
    adj[2] = { 1 , 3 , 5 };
    adj[3] = { 2 , 6 };
    adj[4] = { 1 , 5 , 7 };
    adj[5] = { 2 , 4 , 6 , 8 };
    adj[6] = { 3 , 5 , 9 };
    adj[7] = { 4 , 8 };
    adj[8] = { 5 , 7 , 9 };
    adj[9] = { 6 , 8 };

    cout << findAns(start , length);

    return 0;
}

/*

a --> INPUT :

2 8

a --> OUTPUT :

36

b --> INPUT :

5 10

b --> OUTPUT :

84

c --> INPUT :

9 13

c --> OUTPUT :

8

*/
