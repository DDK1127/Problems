#include<iostream>
#include<vector>

using namespace std;

int main(){
    int times, num, n;
    vector<int> vv;
    cin >> times;

    while(times-- > 0){
        int result = 0;

        cin >> num;
        for(int i = 0;i < num; i++){
            cin >> n;
            vv.push_back(n);
        }
        for(int i = 0; i < vv.size(); i++){
            for(int j = i; j< vv.size(); j++){
                if(vv[i] > vv[j]){
                    swap(vv[i], vv[j]);
                    result++;
                }
            }
        }
        vv.clear();
        cout << "Optimal train swapping takes "<< result << " swaps." << endl;
    }
    return 0;
}
