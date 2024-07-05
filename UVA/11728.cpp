#include<iostream>
using namespace std;

int main(){
    int number, size, sum, result, times = 0;
    bool find;
    while(cin >> number && (number != 0)){
        result = 0, find = false;
        int arr[100];
        for(int i = 1; i < number; i++){
            size = 0, sum = 0;
            for(int j = 1; j <= i; j++){
                if(i % j == 0)
                    arr[size++] = j;
            }
            for(int k = 0; k < size; k++)
                sum += arr[k];
                
            if(sum == number){
                result = arr[size-1];
                find = true;
            }
        }
        if(number == 1)
            cout << "Case " << ++times << ": " << 1 << endl;
        else if(result != 0)
            cout << "Case " << ++times << ": " << result << endl;
        else if(find == false)
            cout << "Case " << ++times << ": " << -1 << endl;
    }
    return 0;
}