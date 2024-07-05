#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long number, m, result;
    bool isBoring;
    vector<long long> arr;

    while (cin >> number >> m){
        arr.push_back(number);
        isBoring = false;
        if(m > number || m <= 1 || number <= 1){
            cout << "Boring!";
        }
        else{
            while(number % m == 0){
                number /= m;
                arr.push_back(number);
            }
            if(number % m != 0 && number != 1){
                cout << "Boring!";
                isBoring = true;
            }
            if(isBoring == false){
                cout << arr[0];
                for(int i = 1; i < arr.size(); i++){
                    cout << " " << arr[i];
                }
            }
        }
        cout << endl;
        arr.clear();
    }
    return 0;
}