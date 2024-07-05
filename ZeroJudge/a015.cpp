#include<bits/stdc++.h>
using namespace std;

int main(){
    int m, n, input;
    while(cin >> m >> n){
        vector<vector<int> > vv(max(m,n), vector<int>(max(n,m)));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> input;
                vv[j][i] = input;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)      
                cout << vv[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}