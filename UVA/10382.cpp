#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<double, double> &a, pair<double, double> &b){
    if(a.first == b.first)
        return a.second > b.second;
    return a.first < b.first; 
}

int main(){
    int n;
    double l , w, p, r, d;
    vector<pair<double, double> > vv;
    while(cin >> n >> l >> w){
        int ans = 0;
        double right = 0;
        for(int i = 0; i < n; i++){
            cin >> p >> r;
            if(r > w/2){
                d = sqrt(r*r - w/2*w/2);
                vv.push_back({p-d, p+d});
            }
        }
        sort(vv.begin(), vv.end(), cmp);

        for(int i = 0; i < vv.size(); i++){
            if(vv[i].first <= right){
                for(int j = i+1; j < vv.size() && vv[j].first <= right ; j++)
                    if(vv[j].second > vv[i].second)
                        i = j;
                ans++;
                right = vv[i].second;
                if(right >= l)
                    break;
            }
            else
                break;
        }
        if(right >= l)
            cout << ans << endl;
        else
            cout << "-1" << endl;

        // for(int i = 0; i < vv.size(); i++)
        //     cout << vv[i].first << ", " << vv[i].second << endl;

        vv.clear();
    }
}