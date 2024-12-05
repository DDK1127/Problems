#include<bits/stdc++.h>
using namespace std;

int main(){
    
	int a, b; // for input;
	int weight_limit, number;
	
	vector<int> weight(1, 0);
	vector<int> value(1, 0);

	cout << "Please Input the Number of item." << endl;
	cin >> number;
	cout << "Please Input the Weight Limit." << endl;
 	cin >> weight_limit;
	cout << "Please sequence Input the item Weight and Value." << endl;

	for(int i = 0; i < number; i++){
		cin >> 	a >> b;
		weight.push_back(a);
		value.push_back(b);
	}

	vector<vector<int> > DP(number+1, vector<int> (weight_limit+1, 0));
	// so Row is how many items i choose, Col is how many weight i can capacity now.

	for(int j = 1; j <= weight_limit; j++){
		for(int i = 1; i <= number; i++){
			if(j < weight[i]) // if knapsack capacity not enough.
				DP[i][j] = DP[i-1][j];  // then choose (i-1) items.
			else{
				int not_take = DP[i-1][j]; 
				int take = DP[i-1][j-weight[i]]+value[i]; // look for table the i-1 items, remaining capacity.

				if(take > not_take)
					DP[i][j] = take;
				else 
					DP[i][j] = not_take;
				/*
				 if((DP[i][j-weight[i]] + value[i]) > DP[i-1][j])
				 	DP[i][j] = DP[i][j-weight[i]] + value[i];
				 else 
				 	DP[i][j] = DP[i-1][j];
				 */ 
			}
		}
	}
	// Print DP table.
	for(int i = 0; i <= number; i++){
		for(int j = 0; j <= weight_limit; j++)
			cout << DP[i][j] << "\t";
		cout << endl;
	}

	cout << "Maximal Value = " << DP[number][weight_limit] << endl;

	return 0;
}
