// UVA 1118.Binary Stirling Numbers
#include<bits/stdc++.h>
using namespace std;


int main(){

    int times, m, n;
    cin >> times;
    
    while(times-- > 0){
        cin >> n >> m;
        if(m == n)
            return 1;
        if(m % 2 == 1 && n % 2 == 1)
            cout << 1 << endl;
        else

    }

    return 0;
}