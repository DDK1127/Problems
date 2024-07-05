#include<iostream>
using namespace std;
//undone

inline int fib(int n){
    if(n <= 1)
        return 1;
    else
        return fib(n-1)+fib(n-2);
}

int main(){
    int n, times;
    int arr[64] = {0};
    int result[39];
    for(int i = 0; i <= 39; i++){
        arr[i] = fib(i);
    }
    cin >> times;
    while(times-- > 0){
        cin >> n;
        bool start = false;
        cout << n << " = ";
        for(int i = 39; i > 0; i--){
            if(n >= arr[i]){
                start = true;
                n -= arr[i];
                cout << "1";
            }
            else if(start == false){}
            else 
                cout << "0";
        }
        cout << " (fib)" <<endl;
    }

    return 0;
}