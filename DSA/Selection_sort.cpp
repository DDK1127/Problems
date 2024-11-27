#include<bits/stdc++.h>
using namespace std;

void Print(vector<int> &arr, int n){
    for(int i = 0; i < n-1; i++)
        cout << arr[i] << ", ";
    cout << arr[n-1] << endl;
}

void Selection_sort(vector<int> &arr){
    int n = arr.size();
    for(int i = 0; i < n-1; i++){
        int m = i+1, temp = arr[i+1];
        for(int j = i+1; j < n; j++){
            if(temp > arr[j]){
                temp = arr[j];
                m = j;
            }
        }
        swap(arr[m], arr[i]);
        cout << "step " << i+1 << " => ";
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

    Selection_sort(arr);

    cout << "\nResult = > " << endl;
	Print(arr, n);

    return 0;
}