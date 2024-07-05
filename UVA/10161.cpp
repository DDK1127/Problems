#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n;
    while (cin >> n && n != 0){
        int s = sqrt(n);
        int x , y;
        if (s % 2 == 0){
            if(n == pow(s, 2))
                x = s, y = 1;
            else if(n <= (pow(s, 2)+s+1))
                x = s+1, y = n-pow(s, 2);
            else if(n > (pow(s, 2)+s+1))
                x = pow(s+1, 2)-n+1, y = s+1;
            else
                cout << "my design program probelm." << endl;
        }
        else{
            if(n == pow(s, 2))
                x = 1, y = s;
            else if(n <= (pow(s, 2)+s+1))
                x = n-pow(s, 2), y = s+1;
            else if(n > (pow(s, 2)+s+1))
                x = s+1, y = pow(s+1, 2)-n+1;
            else
                cout << "my design program probelm." << endl;
        }
        cout << x << " " << y << endl;
    }
    return 0;
}
