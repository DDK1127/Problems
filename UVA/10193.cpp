#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll binary_to_decimal(string s){
	int n = s.size();
	ll temp = 1, res = 0;
	for(int i = n-1; i >= 0; i--){
		res += (s[i]-'0')*temp;
		temp*=2;
	}
	return res;
}

ll  gcd(ll a, ll b){
	if(a % b == 0)
		return b;
	else
		return gcd(b, a%b);
}

int main(){

	int t;
	string s1, s2;

	while(t--){
		cin >> s1 >> s2;
		cout << binary_to_decimal(s1) << endl;
		cout << binary_to_decimal(s2) << endl;
		cout << "gcd result = " << gcd(binary_to_decimal(s1), binary_to_decimal(s2)) << endl;
	}
	return 0;
}
