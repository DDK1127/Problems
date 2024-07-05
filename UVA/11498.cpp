#include<iostream>
using namespace std;

int main(){
    int times ,x ,y, testx, testy;
    while(cin >> times){
        if(times == 0)
            break;
        cin >> x >> y;
        for(int i = 0; i < times; i++){
            cin >> testx >> testy;
            if(x == testx || y == testy)
                cout << "divisa" << endl;
            else if(testx > x && testy > y)
                cout << "NE" << endl;
            else if(testx < x && testy > y)
                cout << "NO" << endl;
            else if(testx > x && testy < y)
                cout << "SE" << endl;
            else
                cout << "SO" << endl;
        }
    }
    return 0;
}