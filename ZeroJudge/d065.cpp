#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> vv(3);
    for(int i = 0; i < 3; i++)
        cin >> vv[i];
    sort(vv.begin(), vv.end(), greater<int>());
    cout << vv[0] << endl;
    return 0;
}