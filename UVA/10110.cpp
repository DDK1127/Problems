// UVA 10110. Light, more light

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n, r;
    while(cin >> n && n != 0){
        r = (ll)sqrt(n);
        if(n == r*r)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}

// To determine whether a factor is odd or even, use perfect square numbers.