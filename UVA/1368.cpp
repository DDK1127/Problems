#include<iostream>
using namespace std;

int main(){
    int times, n, l;
    string str;
    cin >> times;
    while(times-- > 0){
        cin >> n >> l;

        string s[n];
        char result[l];
        for(int i = 0; i < n; i++){
            cin >> str;
            s[i] = str;
        }        
        for(int i = 0; i < l; i++){
            int arr[4] = {0, 0, 0, 0};// 0 = A, 1 = T, 2 = G, 3 = C

            for(int j = 0; j < n; j++){
                if(s[j][i] == 'A'){arr[0]++;}
                else if(s[j][i] == 'C'){arr[1]++;}
                else if(s[j][i] == 'G'){arr[2]++;}
                else if(s[j][i] == 'T'){arr[3]++;}
            }
            int max = 0, t = 0;
            for(int k = 0; k < 4; k++){
                if(arr[k] > max){
                    max = arr[k];
                    t = k;
                }
            }
            if(t == 0)
                result[i] = 'A';
            else if(t == 1)
                result[i] = 'C';
            else if(t == 2)
                result[i] = 'G';
            else if(t == 3)
                result[i] = 'T';
        }
        
        for(int i = 0; i < l; i++){
            cout << result[i];
        }
        int error = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < l; j++){
                if(result[j] != s[i][j])
                    error++;
            }
        }
        cout << endl << error << endl;
    }
    return 0;
}