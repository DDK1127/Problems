// UVA 10107. What is the Median?
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v(10005);
    int input, n = 0, temp;
    while(cin >> input){
        int i , j;
        v[n] = input;
        for(i = 0; i < n; i++){
            if(input < v[i]){
                for(j = n; j > i; j--)
                    v[j] = v[j-1];
                v[i] = input;
                break;
            }
        }
        n++;
        if(n%2)
            cout << v[n/2] << endl;
        else
            cout << (v[n/2]+v[(n/2)-1])/2 << endl;
    }
    return 0;
}