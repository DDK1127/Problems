#include<iostream>
#include<math.h>
using namespace std;

int binary(int n){
    int result = 0;
    for(int i = 13; i >= 0; i--){
        if(n >= pow(2, i)){
            n -= pow(2, i);
            result++;
        }
    }
    return result;
}
int hex(int n){
    int result = 0;
    for(int i = 4; i > 0; i--){
        int now;
        if(n >= pow(10, i-1)){
            now = n/pow(10, i-1);
            n -= now*pow(10, i-1);
            for(int i = 3; i >= 0; i--){
                if(now >= pow(2,i)){
                    now -= pow(2,i);
                    result++;
                }
            }
        }
    }
    return result;
}
int main(){
    int times, n;
    cin >> times;
    while(times-- > 0){
        cin >> n;
        cout << binary(n) << " " << hex(n) << endl;
    }
    return 0;
}
