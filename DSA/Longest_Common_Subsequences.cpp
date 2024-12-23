#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int> > &v){
    int m = v.size(), n = v[0].size();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            cout << v[i][j] << "  ";
        cout << endl;
    }
}

void show(vector<vector<int> > &record, string s, int n) {
    int i = record.size() - 1, j = record[0].size() - 1;
    vector<char> seq(n); 
    int l = n; 

    while (l > 0) {
        if (record[i][j] == 0) { 
            seq[--l] = s[i-1]; 
            i--;
            j--;
        } else if (record[i][j] == 1) 
            j--;
        else 
            i--;
    }

    cout << "The Longest Common Subsequence = ";
    for (int i = 0; i < n; i++)
        cout << seq[i];
}

int LCS(string a, string b){
    int m = a.size(), n = b.size();
    vector<vector<int> > s(m+1, vector<int>(n+1, 0));
    vector<vector<int> > record(m+1, vector<int>(n+1, 0));
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i-1] == b[j-1]){
                s[i][j] = s[i-1][j-1]+1;
                record[i][j] = 0; // 0 => form left-top.
            }
            else if(s[i][j-1] > s[i-1][j]){  
                s[i][j] = s[i][j-1];
                record[i][j] = 1; // 1 => form left.
            }
            else {
                s[i][j] = s[i-1][j];
                record[i][j] = 2; // 2 => from top.
            }
        }
    }

    // print(s);
    show(record, a, s[m][n]);
    cout << endl;

    return s[m][n];
}

int main(){
    string s1, s2;
    // cout << "Please enter two string." << endl;
    cin >> s1 >> s2;
    cout << LCS(s1, s2);
    return 0;
}