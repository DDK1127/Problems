// KMP algo.
#include<bits/stdc++.h>
using namespace std;

void failure(string &s, vector<int> &f){
    f.resize(s.size(), -1);
    int p; 
    for(int i = 1; i < f.size(); i++){
        p = f[i-1];
        while(p != -1 && (s[p+1] != s[i]))
            p = f[p];
        if(s[p+1] == s[i])
            f[i] = p+1;
    }
}
bool KMP(string &a, string &b, vector<int> &f){
    int p = -1;
    for(int i = 0; i < a.size(); i++){
        while(p != -1 && (a[i] != b[p+1]))
            p = f[p];
        if(a[i] == b[p+1])
            p++;
        if(p+1 == b.size()){
            cout << "Match !!! position is => " << i-p << endl;
            p = f[p];
            return true;
        }
    }
    return false;
}

int main(){
    string a, b;
    cout << "Please Enter string." << endl;
    cin >> a;
    cout << "Please Enter want to find substring." << endl;
    cin >> b;
    vector<int> f;
    failure(b, f);
    if(!KMP(a, b, f))
        cout << "Not find substring :" << b << endl;

    return 0;
}