#include<iostream>
#include<algorithm>
#include<typeinfo>
#include<math.h>
#include<vector>
// 暴力法
using namespace std; 

inline int cal(vector<int> vv, int it){
    int total = 0;
    for(int i = 0; i < vv.size(); i++){
        if(it != i){
            total += abs(vv[it]-vv[i]);
        }
    }
    return total;
} 

// int main(){

//     int times, n;
//     cin >> times;

//     while(times-- > 0){
//         cin >> n;

//         vector<int> vv;
//         int num;
//         for(int i = 0; i < n; i++){
//             cin >> num;
//             vv.push_back(num);
//         }
//         int mi = cal(vv,0);
//         for(int i = 1; i < vv.size(); i++){
//             mi = min(mi, cal(vv, i));
//         }
//         cout << mi << endl;
//         vv.clear();
//     }
//     return 0;
// }

// 中位數概念

int main(){
    
    int times ;
    cin >> times;

    while(times-- > 0){
        
        int n, num;
        cin >> n;
        vector<int> vv;

        for(int i = 0; i < n; i++){
            cin >> num;
            vv.push_back(num);
        }

        sort(vv.begin(), vv.end());
        int total = 0;
        // cout << typeid((int)vv.size()).name() << endl;
        if((int)vv.size() % 2 == 0){
            int a = (int)vv.size()/2;
            total = min(cal(vv, a), cal(vv, a-1));
        }
        else{
            total = cal(vv, (int)vv.size()/2);
        }
        cout << total << endl;
    }

    return 0;
}