// UVA.573 - The Snail

#include<bits/stdc++.h>
using namespace std;

int main(){
    float h, u, d, f, now, day;
    bool succuss = true;
    while(cin >> h >> u >> d >> f){
        if(h <= 0)
            break;

        now = 0;
        day = 0;
        f = u*(f/100);

        while(1){
            day++;
            if(u >= 0)
                now += u;
            u -= f;
            if(now > h){
                succuss = true;
                break;
            }
            now -= d;
            // cout << "day = " << day << ", up = " << u << ", now = " << now << endl;
            if(now < 0){
                succuss = false;
                break;
            }
        }
        if(succuss)
            cout << "success on day " << day << endl;
        else
            cout << "failure on day " << day << endl;
    }
    return 0;
}