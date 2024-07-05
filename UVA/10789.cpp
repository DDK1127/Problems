#include<iostream>
#include<vector>
using namespace std;

bool isprimenumber(int n);

int main(){

    bool find;
    int times, n = 0;
    char input[2003];
    cin >> times;
    
    while(n++ < times){
        cin >> input;

        int arr[123]= {0};
        for(int i = 0; input[i] != '\0'; i++){
            if(!arr[(int)input[i]])
                arr[(int)input[i]] = 1;
            else
                arr[(int)input[i]]++;
        }

        find = false;
        cout << "Case " << n << ": ";
        for(int i = 0; i < 123; i++){
            if(arr[i]){
                if(isprimenumber(arr[i])){
                    find = true;
                    cout << (char)i;
                }
            }
            else{}
        }
        if(!find)
            cout << "empty";
        cout << endl;
    }

    return 0; 
}

bool isprimenumber(int n){
    int count = 0;
    for(int i = 2; i < n; i++){
        if(n % i == 0)
            count++;
    }
    if(count == 0 && n != 1 && n != 0)
        return true;
    else
        return false;
}