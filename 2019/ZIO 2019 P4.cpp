#include <iostream>
using namespace std;
#define ll long long int

int main() {

    ll n;
    cin >> n;

    cout << n*n*(ll)pow(2,(n-1)*(n-1));

    return 0;
}

/*

a --> INPUT :

3

a --> OUTPUT :

144

b --> INPUT :

4

b --> OUTPUT :

8192

c --> INPUT :

5

c --> OUTPUT :

1638400

*/
