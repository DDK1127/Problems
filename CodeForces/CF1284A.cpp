// https://codeforces.com/problemset/problem/1284/A
// Codeforces 1284A New Year and Naming.

#include<bits/stdc++.h>
using namespace std;

int main(){
	int size1, size2;
	cin >> size1 >> size2;

	string str;
	vector<string> v1, v2;

	for(int i = 0; i < size1; i++){
        cin >> str;
        v1.push_back(str);
	}
	for(int i = 0; i < size2; i++){
        cin >> str;
        v2.push_back(str);
	}

    int times, year;
    string ans;

    cin >> times;

    while(times-- > 0){
        cin >> year;
        ans = v1[(year-1)%size1];
        ans += v2[(year-1)%size2];
        cout << ans << endl;
    }

    /*
	for(auto& it:v1)
            cout << it << " ";
    cout << endl;
    for(auto& it:v2)
            cout << it << " ";
    cout << endl;
    */

	return 0;
}
