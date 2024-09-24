#include<bits/stdc++.h>
using namespace std;

#define ll long long  
/*
void Print_Parens(vector<vector<int> > &c, int i, int j){
	if(i == j)
		cout << "A";
	else{
		cout << "(";
		Print_Parens(c, i, c[i][j]);
		Print_Parens(c, c[i][j]+1, j);
		cout << ")";
	}
}
*/

void Print_Matrix(vector<vector<ll> > & dp){
	for(int i = 0; i < dp.size()-1; i++){
		for(int j = 1; j < dp.size(); j++)
			cout << setw(10) << dp[i][j];
		cout << endl;
	}
}

ll Matrix_Chain(vector<int> &arr){
	int n = arr.size(), l;
	vector<vector<ll> > dp(n, vector<ll>(n, 0));
	vector<vector<int> > record(n, vector<int>(n, 0)); 

	for(l = 2; l < n; l++){
		cout << "l = " << l << endl;
		for(int i = 0; i < n-l; i++){
			int j = i+l;
			dp[i][j] = LLONG_MAX;
			for(int k = i+1; k < j; k++){
				ll cost = dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j];
				cout << "update cost = " << cost << endl;
				if(dp[i][j] > cost){	
					dp[i][j] = cost;
					record[i][j] = k;
				}
			}
		}
		cout << endl;
	}

	Print_Matrix(dp);
	cout << "Result = ";
	return dp[0][n-1];

}


/*
void Print_Parens(vector<vector<int> > &c, int i, int j){
	if(i == j)
		cout << "A";
	else{
		cout << "(";
		Print_Parens(c, i, c[i][j]);
		Print_Parens(c, c[i][j]+1, j);
		cout << ")";
	}
}
*/
				
int main(){
	int n;	
	cout << "Enter the Array size, A = 3x2, B = 2x7 : 3, 2, 7." << endl;
	cin >> n;
	vector<int> arr(n+1, 0);
	for(int i = 0; i < arr.size(); i++){
		cin >> n;
		arr[i] = n;
	}
	cout << (ll)Matrix_Chain(arr) << endl;

	return 0;
}
