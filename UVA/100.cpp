#include<iostream>
using namespace std;

inline int f(int n){
    int time = 1;
    while(n != 1){
        time++;
        if(n%2 != 0)
            n = 3*n+1;
        else
            n /=2;
    }
    return time;
}

int main(){
    int i, j, Max;
    
    while(cin >> i >> j){
        cout << i << " " <<  j << " ";
        if(i > j)
            swap(i, j);
        Max = 0;
        for(int k = i; k <= j; k++)
            Max = max(Max, f(k));
        cout << Max << endl;
    }
    return 0;
}