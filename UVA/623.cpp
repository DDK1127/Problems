#include<bits/stdc++.h>
using namespace std;

vector<int> vv(10000);

int main(){
    int n, m, carry, x;

    while(cin >> n){
        vv[0] = 1;
        m = 1; carry = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < m; j++){
                x = vv[j]*i+carry;
                vv[j] = x%10;
                carry = x/10;
            }
            while(carry > 0){
                vv[m] = carry%10;
                carry /= 10;
                m++;
            }
        }
        vv[m] = '\0';
        cout << n  << "!" << endl;
        for(int i = m-1; i >= 0; i--)
            cout << vv[i];
        cout << endl;
        vv.clear();
    }
    return 0;
}