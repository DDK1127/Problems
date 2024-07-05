#include<bits/stdc++.h>

using namespace std;

int n , m;
int isOdd(int num){
 num = abs(num%2);//餘數可能為負
 return num;
}
bool compare(int a, int b){
 if(a%m != b%m)return a%m < b%m; //N%M 小者前 大者後
 if(isOdd(a) != isOdd(b)) return isOdd(a); //餘數同 奇數前 偶數後
 if(isOdd(a))return a > b; //皆為奇 大奇前 小奇後
 return a < b; //剩餘情況:皆為偶 小偶前 大偶後
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n >> m){
        cout << n << " " << m << endl;
        if(n == 0 && m == 0) break;

        vector<int> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];

        sort(v.begin(), v.end(), compare);
        for(int i = 0; i < n; i++)
            cout << v[i] << endl;
        
    }
    return 0;
}