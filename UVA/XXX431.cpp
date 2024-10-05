#include <bits/stdc++.h>
using namespace std;

struct info{
    int s, t;
    string d;
};

info make_info(int s, int t, string d){
    info i = {s, t, d};
    return i;
};

void Print(vector<info> v, int &ts, int &tt){
    for(int i = 0; i < v.size(); i++){
        ts += v[i].s;
        tt += v[i].t;
    }
    cout << "Score  Time  Description" << endl;
    cout << "-----  ----  -----------" << endl;
    for(int i = 0; i < v.size(); i++)
        cout << setw(3) << v[i].s << "    " << setw(3) << v[i].t << "  " << v[i].d << endl;
    cout << "Total score: " << ts << " points" << endl;
    cout << " Total time: " << tt << " hours" << endl;
}   

int main(){
    int t, score, time, limit;
    string description;
    cin >> t;

    while (t-- > 0){
        int total_score = 0, total_time = 0;
        cin >> limit;
        vector <info> vv;
        vector<int> dp(limit, 0);
        vector<vector<bool> > p(101, vector<bool>(limit, 0));
        while(cin >> score >> time){
            cin.ignore();
            getline(cin, description);
            vv.push_back(make_info(score, time, description));
            // vv.push_back( {score, time, description} );
        }
        // for(int i = 0; i < vv.size(); i++){
        //     cout << "score = " << vv[i].s << ", time = " << vv[i].t << ", des = " << vv[i].d << endl;
        // }
        for(int i = 1; i < limit; i++){
            for(int j = 0; j < vv.size(); j++){
                if(i > vv[j].t){
                    if(dp[i-vv[j].t] + vv[j].s > dp[i])
                        dp[i] = dp[i-vv[j].t] + vv[j].s;
                        p[i][j] = true;
                }
            }
        }
        vector<info> select;
        int l = limit;
        for(int i = 0; i < vv.size(); i++){
            if(p[i][l]){
                select.push_back(vv[i]);
                l -= vv[i].t;
            }
        }
        Print(select, total_score, total_time);
    }
    return 0;
}