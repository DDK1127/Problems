#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int times, total_day, n_day;
    cin >> times;
    while(times-- > 0){
        cin >> total_day;
        cin >> n_day;
        
        int num, result = 0;
        vector<int> vv;

        for(int i = 0; i < n_day; i++){
            cin >> num;
            vv.push_back(num);
        }

        for(int i = 1; i <= total_day; i++){
            if(i % 7 == 0 || i % 7 == 6)
                continue; 
            for(int j = 0; j < vv.size(); j++){
                if(i % vv[j] == 0){
                    result++;
                    break;
                }
            }
        }
        vv.clear();
        cout << result << endl;
    }
    return 0;
}