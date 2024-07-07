#include<bits/stdc++.h>
using namespace std;

struct s{
    int up, down;
    char up_c, down_c;
};

int main(){
    string str;
    while(cin >> str){
        s b, a ={1, 1, str[0], str[0]};

        for(int i = 0; i < str.size(); i++){
            b = a;
            if(str[i] < a.up_c){
                b.down = a.up+1;
                b.down_c = str[i];
            }
            if(str[i] > a.down_c){
                b.up = a.down+1;
                b.up_c = str[i];
            }
            a = b;
        }
        cout << max(a.up, a.down) << endl;
    }
    return 0;
}