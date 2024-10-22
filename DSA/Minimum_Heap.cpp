#include<bits/stdc++.h>
using namespace std;

void adjust(vector<int> &v, int i, int n){ // n can access.
    int temp = v[i];
    int k = i*2+1;
    while(k <= n){
        if(k < n){
            if(v[k+1] < v[k])
                k = k+1;
        }
        if(temp <= v[k])
            break;
        else{
            swap(v[(k-1)/2], v[k]);
            k = k*2+1;
        }
    }
}

void buttom_up_bulid(vector<int> &v){
    int n = v.size();
    for(int i = n/2-1; i >= 0; i--)
        adjust(v, i, n-1);
    
    cout << "After adjust =>" << endl;
    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}

int main(){
    int n, in;
    vector<int> v;
    cout << "How many number input ?" << endl;
    cin >> n;
    while(n--){
        cin >> in;
        v.push_back(in);
    }
    buttom_up_bulid(v);
    return 0;
}