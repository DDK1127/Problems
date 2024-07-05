#include<iostream>
#include<vector>

using namespace std;

vector<vector<char> > vv;
vector<vector<bool> > f;

void dfs(int height, int weight, int i, int j);

int main(){
    int times, weight, height, n = 0;
    
    char c;
    vector<int> result(26, 0);
    cin >> times;

    while(++n <= times){
        cin >> height >> weight;

        int Max = 0;
        vv.resize(height+2);
        f.resize(height+2);
        result.resize(26);

        for(int i = 0; i < height+2; i++){
            vv[i].resize(weight+2, '0');
            f[i].resize(weight+2, false);
        }
        // => 0 & height+1 is bound, use 1 ~ height
        // array[0]-array[height+1] can't touch
        for(int i = 1; i <= height; i++){
            for(int j = 1; j <= weight; j++){
                cin >> c;
                vv[i][j] = c;
            }
        }

        for(int i = 1; i <= height; i++){
            for(int j = 1; j <= weight; j++){
                 bool have = false;
                if(f[i][j] == false){
                    Max = max(Max, ++result[vv[i][j]-'a']);
                    dfs(height, weight, i, j);
                }
            }
        }

        cout << "World #" << n << endl;
        for(int i = Max; i > 0; i--){
            for(int j = 0; j < 26; j++){
                if(result[j] == i)
                    cout << (char)(j+97) << ": " << result[j] << endl;
            }
        }

        vv.clear();
        f.clear();
        result.clear();

        // for(vector<vector<char> >::iterator it; it != vv.end(); ++it){
        //     for(vector<char>::iterator iit = it->begin(); iit != it->end(); ++iit){
        //             cout << *iit << " ";
        //     }
        //     cout << endl;
        // }
        
    }
    return 0;
}

void dfs(int height, int weight, int i, int j){
    if(i > height || i <= 0 || j > weight || j <= 0){f[i][j] = true;}
    if(f[i][j] == false){
        f[i][j] = true; 
        if(!f[i+1][j] && (vv[i][j] == vv[i+1][j]))
            dfs(height, weight, i+1, j);
        if(!f[i-1][j] && (vv[i][j] == vv[i-1][j]))
            dfs(height, weight, i-1, j);
        if(!f[i][j+1] && (vv[i][j] == vv[i][j+1]))
            dfs(height, weight, i, j+1);
        if(!f[i][j-1] && (vv[i][j] == vv[i][j-1]))
            dfs(height, weight, i, j-1);
    }
}