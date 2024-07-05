#include<iostream>
#include<vector>
using namespace std;

int main(){
    int i, j, a; 
    while(cin >> i){
        if(i == 0 || i < 0)
            break;
        int arr[100] = {0};
        j = 0, a = 1;
        while(i > 1){
            arr[j++] = i%2;
            i /= 2;
        };
        cout << "The parity of 1";
        for(int k = j-1; k >= 0; k--){
            cout << arr[k];
            if(arr[k] == 1)
                a++;
        }
        cout << " is " << a << " (mod 2)." << endl;
        
        
    }
    return 0;
}