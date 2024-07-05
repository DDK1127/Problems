#include<iostream>
#include<string.h>

using namespace std;

int main(){
    string str; 
    int count = 0;

    while(getline(cin, str)){
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '"'){
                count++;
                if(count == 2){
                    count = 0;
                    cout << "''";
                }
                else{
                    cout << "``";
                }
            }
            else
                cout << str[i];
        }
        cout << endl;
    }
    return 0;
}