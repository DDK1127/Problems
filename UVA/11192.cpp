#include<iostream>
using namespace std;

int main(){
    int divided, group;
    string str;

    while(cin >> divided){
        if(divided == 0)
            break;
        cin >> str;
        group = (int)str.size()/divided;

        for(int i = 0; i < str.size(); i+=group){
            for(int j = i+group-1; j >= i; j--){
                cout << str[j];
            }
        }
        cout << endl;
    }
    return 0;
}