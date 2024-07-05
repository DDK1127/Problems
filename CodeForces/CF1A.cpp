// https://codeforces.com/problemset/problem/1/A
// Codeforces 1.A Theatre Square
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int m, n, a, l, r;
    cin >> m >> n >> a;
    l = min(m,n), r = max(m, n);
    if(l % a == 0)
        l /= a;
    else{
        l /= a;
        l++;
    }
    if(r % a == 0)
        r /= a;
    else{
        r /= a;
        r++;
    }
    cout << l*r << endl;
    return 0;
}