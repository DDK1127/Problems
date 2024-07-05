// CodeForces 1984-B.Large Addition

#include<bits/stdc++.h>
using namespace std;

long long int p(int k){
    long long int ans = 1;
    for(int i = 0; i < k; i++)
        ans*=10;
    return ans;
}

int main(){
    int t, digit;
    long long int n, l, r;
    cin >> t;

    while(t-- > 0){
        cin >>  n;
        digit = 1;
        l = 0;
        bool zero = false;
        long long int temp = n;
        while(temp >= 10){
            temp /= 10;
            digit++;
            if(temp % 10 == 0)
                zero = true;
        }
        if(n % 10 == 9 || temp != 1 || zero)
            cout << "NO" << endl;
        else{
            for(int i = 1; i < digit; i++)
                l += p(i);
            r = 2*p(digit-1)-2;
            // cout << "l = " << l << ", r = " << r <<  endl;
            if(l <= n && n <= r)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }

    }

    return 0;
}
