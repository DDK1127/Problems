#include <iostream>
using namespace std;

int main(){
    int n;
    long m, wm, temp_m, temp_wm;
    while(cin >> n && n != -1){
        wm = 1, m = 0;
        for(int i = 0; i < n; i++){
            temp_m = m, temp_wm = wm;
            if(i == 0)
                temp_m++;
            else{    
                for(int j = 0; j < m; j++){
                    temp_wm++;
                }
                for(int k = 0; k < wm-1; k++){
                    temp_m++;
                    temp_wm--;
                }
                temp_m++;    
            }
            m = temp_m, wm = temp_wm;
        }
        cout << m << " " << m + wm << endl;
    }
    return 0;
}