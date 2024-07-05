#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, input;
    vector<vector<int> >vv(10, vector<int>(10));

    cin >> t;

    while(t-- > 0){
        for(int i = 0; i < 9; i += 2){
            for(int j = 0; j <= i; j += 2){
                cin >> input;
                vv[i][j] = input;
            }
        }


        for(int i = 2; i < 9; i+=2){
            for(int j = 1; j <= i; j+=2){
                vv[i][j] = (vv[i-2][j-1]-vv[i][j-1]-vv[i][j+1])/2;
            }
        }
        for(int i = 1; i < 9; i += 2){
            for(int j = 0; j <= i; j++){
                vv[i][j] = vv[i+1][j] + vv[i+1][j+1];
            }
        }

        for(int i = 0; i < 9; i++){
            for(int j = 0; j <= i; j++){
                cout << vv[i][j];
                if(j != i)
                    cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}