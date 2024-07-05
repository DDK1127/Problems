#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, c, ans, s = 0;
    cin >> n;
    
    c = n % 10;

    for(int i = 8; i >= 0; i--){
        int p = pow(10, i);
        s += (n/p)*i;
        n %= p;
    }

    for(int j = 0; j < 10; j++){
        int total = (1+9*j+s) % 10;
        if(10-total == c)
            ans = j;
        if(total == 0 && c == 0)
            ans = j;
    }
    switch (ans){
        case 0:
            cout << "AMW" << endl;
            break;
        case 1:
            cout << "BNZ" << endl;
            break;
        case 2:
            cout << "CIP" << endl;
            break;
        case 3:
            cout << "DOQ" << endl;
            break;
        case 4:
            cout << "ER" << endl;
            break;
        case 5:
            cout << "FS" << endl;
            break;
        case 6:
            cout << "GT" << endl;
            break;
        case 7: 
            cout << "HU" << endl;
            break;
        case 8:
            cout << "JVX" << endl;
            break;
        case 9:
            cout << "KLY" << endl;
            break;
        
    }


    return 0;
}