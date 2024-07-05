#include<iostream>
#include<vector>
using namespace std;

int main(){
    int a, b, sum, i;
    vector<int> arr, brr;
    while(cin >> a >> b){
        if(a != 0 && b != 0)
            break;
        sum = 0;
        arr.clear();
        brr.clear();

        while(a >= 10 || b >= 10){
            arr.push_back(a % 10);
            brr.push_back(b % 10);
            a /= 10, b /= 10;
        }
        arr.push_back(a % 10);
        brr.push_back(b % 10);

        for(int j = 0; j < min(arr.size(), brr.size()); j++){
            if(arr[j]+brr[j] >= 10){
                sum++;
                if(arr[j])
                    arr[j+1]++;
            }
        }
        if(sum == 0)
            cout << "No carry operation." << endl;
        else if(sum == 1)
            cout << sum << " carry operation." << endl;
        else
            cout << sum << " carry operations." << endl;
    }
    return 0;
}