#include<bits/stdc++.h>
// TLE

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int times;
    cin >> times;

    for(int t = 1; t <= times; t++){
        string str;
        cin >> str;

        int row = str.size()+1, col = 0, max_col = 0 , min_col = 0;
        pair<char, int> pp;
        vector<pair<char, int> > vv;

        for(int i = 0; i < str.size(); i++){
            if(str[i] == 'R'){
                col++;
                vv.push_back(make_pair('/', col));
            }
            else if(str[i] == 'F'){
                vv.push_back(make_pair('\\', col));
                col--;
            }
            else if(str[i] == 'C'){
                vv.push_back(make_pair('_', col+1));
                if(max_col < col+1)
                    max_col = col+1;
            }
            max_col = max(max_col, col);
            min_col = min(min_col, col);
        }

        cout << "Case #" << t << ":" <<endl;
        for(int i = max_col; i > min_col; i--){
            cout << "| ";
            for(int k = 0; k < vv.size(); k++){
                if(i != vv[k].second)
                    cout << ' ';
                else
                    cout << vv[k].first;
            }
            cout << endl;
        }
        cout << "+";
        for(int r = 0; r < row+1; r++)
            cout << "-";
        cout << endl;
            
    }

    return 0;
}