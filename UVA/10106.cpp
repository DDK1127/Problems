// UVA 10106.Product

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2;
    while(cin >> s1 >> s2){
        if(s1 == "0" || s2 == "0"){
            cout << "0" << endl;
            continue;
        }

        int n = s1.size(), m = s2.size(), p, temp, carry;
        vector<int> result(n+m, 0);

        for(int i = n-1; i >= 0; i--){
            p = n-i-1;
            carry = 0;
            for(int j = m-1; j >= 0; j--){
                temp = (s1[i]-'0')*(s2[j]-'0')+carry;
                result[p] += temp;
                carry = result[p]/10;
                result[p] %= 10;
                p++;
            }
            result[p] += carry;
            result[p+1] = result[p]/10;
            result[p] %= 10;
        }

        bool first = false;
        for(int k = result.size()-1; k >= 0; k--){
            if(result[k] != 0)
                first = true;
            if(first)
                cout << result[k];
        }
        cout << endl;
    }
    return 0;
}