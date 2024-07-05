// CodeForces - 1977B-Binary Colouring
#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long int times, n;
    vector<long int> vv;
    bool carry;

    cin >> times;
    while(times-- > 0){
        carry = false;
        cin >> n;
        
        while(n){
            vv.push_back(n%2);
            n/=2;
        }
        for(int i = 1; i < vv.size(); i++){
            if(vv[i-1] && vv[i]){
                vv[i-1] = -1;
                vv[i] = 0;
                carry = true;
            }
            else if(vv[i] && carry) // carry flag(T) not change.
                vv[i] = 0;
            else if(!vv[i] && carry){
                vv[i] = 1;
                carry = false;
            }
            // impossible is v[i-1] = 1, carry = 1
            else{}
        }
        if(carry) // add last one 
            vv.push_back(1);

        cout << vv.size() << endl;
        for(auto& it : vv)
            cout << it << " ";
        cout << endl;

        vv.clear();
    }

    return 0;
}