// UVA 10101.Bangla Numbers.
#include <iostream>
#include <iomanip>
using namespace std;
#define ll long long int 

void Bangla(ll n);

int main(){
	int t = 0;
	ll input;
	while(cin >> input){
		cout << setw(4) << ++t << ".";
		if(input)
			Bangla(input);
		else
			cout << " 0";
		cout << endl;
	}
	return 0;
}
void Bangla(ll n){
	if(n/10000000){
		Bangla(n/10000000);
		cout <<" kuti";
		n%=10000000;
	}
	if(n/100000){
		Bangla(n/100000);
		cout << " lakh";
		n%=100000;
	}
	if(n/1000){
		Bangla(n/1000);
		cout << " hajar";
		n%=1000;
	}
	if(n/100){
		Bangla(n/100);
		cout << " shata";
		n%=100;
	}
	if(n)
		cout << " " << n;
}


