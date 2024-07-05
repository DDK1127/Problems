#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int x, num, input, total;
    string str;
    vector<int> vv;
    while(cin >> x){
        cin.ignore();
        getline(cin, str);
        stringstream ss(str);
        while(ss >> input)
            vv.push_back(input);

        // for(auto &it : vv)
        //     cout << it << " ";
        // cout << endl;

        total = 0;
        for(int i = vv.size()-1; i > 0; i--){
            total += i*pow(x, i-1)*vv[vv.size()-i-1];
        }
        cout << total << endl;
        vv.clear();
    }
    return 0;
}