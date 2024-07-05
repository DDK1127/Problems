#include<bits/stdc++.h>
using namespace std;
// uva fail, zero judge ac.

int change(char a){
    int n = a - '7';
    return n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    int before_base, after_base;
    while(cin >> str){
        cin >> before_base >> after_base;
        int result = 0, n;
        if(str == "0"){ // to uva input number = 0, output 0.
            cout << "0" << endl;
            continue;
        }
        for(int i = 0; i < str.size(); i++){
            if(str[i] - 'A' >= 0)
                n = change(str[i]);
            else 
                n = str[i] - '0';
            result += pow(before_base, str.size()-i-1)*n;
        }

        if(result > pow(after_base, 7)){
            cout << "ERROR" << endl;
            continue;;
        }
        bool display = false;
        for(int i = 0; i < 7; i++){
            if(result >= pow(after_base, 6-i)){
                display = true;
                int p = pow(after_base, 6-i);

                if(result / p >= 10){
                    switch (result/p){
                    case 10:
                        cout << 'A';
                        break;
                    case 11:
                        cout << 'B';
                        break;
                    case 12: 
                        cout << 'C';
                        break;
                    case 13:
                        cout << 'D';
                        break;
                    case 14: 
                        cout << 'E';
                        break;
                    case 15:
                        cout << 'F';
                        break;
                    default:
                        cout << "error";
                        break;
                    }
                }
                else 
                    cout << result / p;
                result %= p;
            }
            else{
                if(display)
                    cout << "0";
            }
        }
        cout << endl;
    }
    return 0;
}