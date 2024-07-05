#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string str;
    while(cin >> str){
        int length = str.size();
        for(int i = 0; i < length; i++)
            cout << (char)(str[i]-7);
        cout << endl; 
    }
    return 0; 
}