// CodeForces 1985A-Creating Words
#include<bits./stdc++.h>
using namespace std;

int main(){
    string str;
    int times;
    
    cin >> times;
    cin.ignore();
    while(times-- >= 0){
        getline(cin, str);
        swap(str[0], str[4]);
        cout << str << endl;
    }
    return 0;
}