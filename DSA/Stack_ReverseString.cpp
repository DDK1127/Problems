#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    stack<char> ss;

    while(cin >> str){
        for(int i = 0; i < str.size(); i++) 
            ss.push(str[i]);
        while(!ss.empty()){cout << ss.top() << " ";ss.pop();}
        cout << endl;
    }

    return 0;
}