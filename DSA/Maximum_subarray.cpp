// use Dynamic-Programming
// Time complexity = O(n)
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    vector<int> a;
    int t;
    while(cin >> t)
        a.push_back(t);
    int r = a[0], Max = a[0];
    int start = 0, end = 0, from = 0;

    for(int i = 1; i < a.size(); i++){
        a[i] > r+a[i] ? r = a[i], start = i : r += a[i];
        if(Max < r)
            Max = r, end = i, from = start;
    }
    
    cout << "Max Value = " <<  Max << ",  A[" << from << "] -> A[" << end << "]" <<  endl;
    return 0;
}