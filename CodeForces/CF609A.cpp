// https://codeforces.com/problemset/problem/609/A
// Codeforces 609A USB Flash Drives

#include<bits/stdc++.h>
using namespace std;

int main(){

    int num, total_size, input, counter = 0;
    vector<int> vv;

    cin >> num >> total_size;
    for(int i = 0; i < num; i++){
        cin >> input;
        vv.push_back(input);
    }
    sort(vv.begin(), vv.end());

    while(!vv.empty() && total_size > 0){
        total_size -= vv.back();
        vv.pop_back();
        counter++;
    }
    cout << counter << endl;
    /*
    for(auto& it:vv)
            cout << it << " ";
    cout << endl;
    */
    return 0;
}
