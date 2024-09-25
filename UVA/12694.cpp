// Meeting Room Arrangement.
#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2){
    return p1.second < p2.second;
}

int main(){
    int t, s, f;
    cin >> t;

    pair<int, int> p;

    while(t-- > 0){
        vector<pair<int, int> > v;
        while(cin >> s >> f){
            if(s == 0 && f == 0)
                break;
            v.push_back(make_pair(s, f));
        }
        sort(v.begin(), v.end(), cmp);

        // for(int i = 0; i < v.size(); i++)
        //     cout << v[i].first << ", " << v[i].second << endl;
        int ans = 1, last = v[0].second;
        for(int i = 1; i < v.size(); i++){
            if(v[i].first >= last){
                last = v[i].second;
                ans++;
            }
        }
        v.clear();
        cout << ans << endl;
    }
    return 0;
}