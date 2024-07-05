#include<iostream>
#include<vector>
using namespace std;

int main(){
    int times, l, temp, result;
    vector<int> v;
    cin >> times;
    while(times-- > 0){
        cin >> l;
        result = 0;
        for(int i = 0; i < l; i++){
            cin >> temp;
            v.push_back(temp);
        }
        for(int i = 1; i < l; i++){
            for(int j = 0; j < i; j++){
                if(v[i] >= v[j])
                    result++;
            }
        }
        cout << result << endl;
        v.clear();
    }
    return 0;
}
