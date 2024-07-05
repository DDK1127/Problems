#include<iostream>
using namespace std;

string str[128];

int main(){
    int c = 0,  r = 0;

    while(getline(cin, str[c])){
        r = max(r, (int)str[c++].size());
    }
    for(int i = 0; i < r; i++){
        for(int j = c-1; j >= 0; j--){
            if(str[j].size() <= i)
                cout << ' ';
            else 
                cout << str[j][i];
        }
        cout << "\n";
    }
    return 0;
}