#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// uva can't pass but zerojudge can pass , test data can pass.
int main(){
    int w, h;
    

    while(cin >> w >> h){
        vector<int> vv;
        vector<int> number;
        bool possible = true;

        vv.push_back(w);
        vv.push_back(h);
        number.push_back(w);
        number.push_back(h);

        for(int i = 0; i < 5; i++){
            cin >> w >> h;
            vv.push_back(w);
            vv.push_back(h);
        }

        sort(vv.begin(), vv.end());

        

        int times = 0;
        if(vv[0] == vv[1] && vv[0] == vv[2] && vv[0] == vv[3]){}
        else
            possible = false;
        if(vv[4] == vv[5] && vv[4] == vv[6] && vv[4] == vv[7]){}
        else
            possible = false;
        if(vv[8] == vv[9] && vv[8] == vv[10] && vv[8] == vv[11]){}
        else
            possible = false;

        vv.push_back(-1);

        for(int i = 0; i < vv.size()-1; i++){
            for(int j = i+1; j < vv.size()-1; j++){
                if(vv[i] == vv[j]){
                    vv[i] = -1; 
                    vv[j] = -1;
                }
            }
        }

        for(int i = 0; i < vv.size(); i++){
            if(vv[i] != -1)
                possible = false;
        }

        if(possible)
            cout << "POSSIBLE" << endl;
        else
            cout << "IMPOSSIBLE" << endl;

    }
    return 0;
}