#include<iostream>
#include<vector>

using namespace std;
// undone

inline int Find(const vector<vector<int> > &vv, int size, int r, int c, int n){
    int sum = 0;
    if(r+size >= n || c+size >= n)
        return 0;
    for(int i = r; i < r+size; i++){
        for(int j = c; j < c+size; j++){
            sum += vv[i][j];
        }
    }
    return sum;
};

int main(){

    int n, a, Max = 0;
    cin >> n;
    vector<vector<int> > vv(n);
    for(int i =0; i < n; i++)
        vv[i].resize(n, 0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a;
            vv[i][j] = a;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int s = 1; s < n; s++){
                Max = max(Max, Find(vv, s, i, j, n));
            }
        }
    }
    cout << Max << endl;
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << vv[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}