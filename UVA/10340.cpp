#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main(){
    string s1, s2;

    while(cin >> s1 >> s2){
        int r = s1.size(), c = s2.size();
        vector<vector<int> > vv(r+1, vector<int>(c+1, 0));
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                if(s1[i-1] == s2[j-1])
                    vv[i][j] = vv[i-1][j-1]+1;
                else
                    vv[i][j] = max(vv[i-1][j], vv[i][j-1]);
            }
        }
        if(vv[r][c] == s1.size())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        vv.clear();
    }
    return 0;
}