#include <iostream>
using namespace std;
#define ll long long int

int main() {

    ll n;
    cin >> n;

    cout << n*n*(ll)pow(2,(n-1)*(n-1));

    return 0;
}
