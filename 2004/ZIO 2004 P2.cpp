#include <iostream>
#include <vector>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f3f

int main() {

    string s;
    cin >> s;

    reverse(s.begin(),s.end());

    ll ans = 1;

    for(auto i : s){
        ans *= 2;
        if(i == 'b') ans--;
    }

    cout << ans;

    return 0;
}

/*

a --> INPUT :

bbaaba

a --> OUTPUT

45

b --> INPUT :

babbabba

b --> OUTPUT :

147

c --> INPUT :

ababaaabaa

c --> OUTPUT :

886

*/
