#include<bits/stdc++.h>

using namespace std;
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ;
    while(cin >> n){
        if(n == 0) continue;
        int g = 0; 
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                g += gcd(i, j);
            }
        }
        cout << g << endl;
    }
    return 0;
}