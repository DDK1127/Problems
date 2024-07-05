#include <bits/stdc++.h>
using namespace std;

void interchangeRow(vector<vector<int> > &vv, int a,int b){
    int n = vv.size();
    int temp;
    for(int c = 0; c < n; c++){
        // swap(vv[a][c], vv[b][c]);
        temp = vv[a][c];
        vv[a][c] = vv[b][c];
        vv[b][c] = temp;
    }
};
void interchangeCol(vector<vector<int> > &vv, int a,int b){
    int n = vv.size();
    int temp;
    for(int r = 0; r < n; r++){
        // swap(vv[a][c], vv[b][c]);
        temp = vv[r][a];
        vv[r][a] = vv[r][b];
        vv[r][b] = temp;
    }
};
void inc(vector<vector<int> > &vv){
    int n = vv.size();
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            vv[r][c]++;
            if(vv[r][c] >= 10)
                vv[r][c] = 0;
        }
    }
}

void dec(vector<vector<int> > &vv){
    int n = vv.size();
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            vv[r][c]--;
            if(vv[r][c] < 0)
                vv[r][c] = 9;
        }
    }
}

vector<vector<int> > transpose(vector<vector<int> > &vv){
    int n = vv.size();
    vector<vector<int> > tempv(n, vector<int>(n, 0));
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            tempv[c][r]= vv[r][c];
        }
    }
    return tempv;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int times;
    cin >> times;

    int n, input, optr; // n is n by n  Matrix, optr is times of operater.
    int a, b; // operator number.
    string str; // str is operator name.
    for(int t = 1; t <= times; t++){
        cin >> n;
        vector<vector<int> > vv(n, vector<int>(n, 0));
        for(int r = 0; r < n; r++){
            cin >> input;
            for(int c = n-1; c >= 0; c--){
                vv[r][c] = input % 10;
                input/=10;
            }
        }

        // for(int r = 0; r < n; r++){
        //     for(int c = 0; c < n; c++)
        //         cout << vv[r][c];
        //     cout << endl;
        // }

        cin >> optr;
        while(optr-- > 0){
            cin >> str;
            if(str == "row"){
                cin >> a >> b;
                interchangeRow(vv, a-1, b-1);
            }
            else if(str == "col"){
                cin >> a >> b;
                interchangeCol(vv, a-1, b-1);
            }
            else if(str == "inc")
                inc(vv);
            else if(str == "dec")
                dec(vv);
            else if(str == "transpose")
                vv = transpose(vv);
            else    
                cout << "you operations command is wrong." << endl;
        }

        cout << "Case #"<< t <<endl;
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++)
                cout << vv[r][c];
            cout << endl;
        }
        cout << endl;
        

        for(int i = 0; i < n; i++)
            vv[i].clear();
        vv.clear();
    }
    

    return 0;
}