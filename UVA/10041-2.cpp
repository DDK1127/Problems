#include<iostream>
using namespace std;

int main(){
    int times, t, number, sum;
    vector<int> vv;

    cin >> times;

    while(times-- > 0){
        vv.clear();
        sum = 0;

        cin >> t;

        for(int i = 0; i < t; i++){
            cin >> number;
            vv.push_back(number);
        }
        sort(vv.begin(), vv.end());

        int mid = vv[vv.size()/2];

        for(int i = 0; i < t; i++){
            sum += abs(mid-vv[i]);
        }
        cout << sum << endl;
    }

    return 0;
}