// Bars
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, l , n, input;
    cin >> t;

    while(t-- > 0){
        cin >> l >> n;

        vector<bool> ans(l, false);
        vector<int> vv;
        if(l)
            ans[0] = true;
        for(int i = 0; i < n; i++){
            cin >> input;
            vv.push_back(input);
        }
        sort(vv.begin(), vv.end());

        for(int i = n-1; i >= 0; i--){
            for(int k = l; k >= vv[i]; k--){
                ans[k] = ans[k] | ans[k-vv[i]];
            }
        }
        if(l == 0) cout << "YES" << endl;
        else if(ans[l]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}