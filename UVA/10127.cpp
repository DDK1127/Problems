// UVA 10127.Ones

#include<bits/stdc++.h>
using namespace std;

int main(){
    int number, t, counter;
    while(cin >> number){
        counter = 0;
        t = 1;
        while(1){
            counter++;
            t = t % number;
            if(t == 0)
                break;
            t *= 10;
            t++;
        }
        cout << counter << endl;
    }
    return 0;
}