#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, d, r;

    while(cin >> n >> d >> r){
        if(n == 0 && d == 0 && r == 0)
            break;

        vector<int> mr(n), nr(n);
        int input;
        for(int i = 0; i < n; i++){
            cin >> input;
            mr[i] = input;
        }
        for(int i = 0; i < n; i++){
            cin >> input;
            nr[i] = input;
        }

        
    }
    return 0;
}