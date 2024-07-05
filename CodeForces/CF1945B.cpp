// https://codeforces.com/problemset/problem/1945/B
// Codeforces 1945 B.Fireworks

#include<bits/stdc++.h>
using namespace std;

int main(){

    long long int times, a, b, t, counter;
    cin >> times;
    while(times-- > 0){
        cin >> a >> b >> t;
        counter = ((a+t)/a)+((b+t)/b);
        cout << counter << endl;
    }
    return 0;
}
