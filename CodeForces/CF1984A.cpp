// 1984A - Strange SPlitting
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, input;
    vector<int> vv;

    cin >> t;
    while(t-- > 0){
        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> input;
            vv.push_back(input);
        }
        if(vv[0] == vv[n-1])
            cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            cout << "BR";
            for(int i = 2; i < n; i++)
                cout << "B";
            cout << endl;
        }
        vv.clear();
    }
    return 0;
}