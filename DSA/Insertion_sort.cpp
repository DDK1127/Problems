#include<bits/stdc++.h>
using namespace std;

void Print(vector<int> &arr, int n){
    for(int i = 0; i < n-1; i++)
        cout << arr[i] << ", ";
    cout << arr[n-1] << endl;
}

void Insertion_sort(vector<int> &arr){
	int n = arr.size();

	for(int i = 1; i < n; i++){
		int temp = arr[i];
		int j = i-1;
		while(j >= 0 && temp < arr[j]){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
		cout << "step " << i << " => ";
        Print(arr, n);
	}
}

int main(){
	int n, input;
	vector<int> arr;
	
	cout << "Please input size." << endl;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> input;
		arr.push_back(input);
	}
	
	Insertion_sort(arr);

	cout << "\nResult = > " << endl;
	Print(arr, n);

	return 0;
}
