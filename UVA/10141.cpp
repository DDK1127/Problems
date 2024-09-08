#include<bits/stdc++.h>
using namespace std;
/*
    we don't care about rfp contant...
    just find the r is biggest, and satisfy condition.
*/

struct Company{
    int n, r;
    double d;
    string name;
};

bool cmp(Company a, Company b){ // only need to compare.
    if(a.r != b.r)
        return a.r > b.r;
    else if(a.d != b.d)
        return a.d < b.d;
    else    
        return a.n < b.n;
}

int main(){
    int n, p, c = 1;
    string s, name;
    vector<string> rfp; // even don't need...
    while(cin >> n >> p){
        cin.ignore();
        if(n == 0 && p == 0)
            break;
        for(int i = 0 ; i < n; i++){
            getline(cin, s);
            rfp.push_back(s);
        }
        double d;
        int r;
        Company company[p];
        for(int i = 0; i < p; i++){
            getline(cin, name);
            cin >> d >> r;
            cin.ignore();
            company[i] = {i, r, d, name};// struct assignment.
            for(int j = 0; j < r; j++) // cin and flush it.
                getline(cin , s); 
        }
        sort(company, company+p, cmp); //find priority height, let it in [0].
        if(c > 1) cout << endl;
        cout << "RFP #" << c++ << endl;
        cout << company[0].name << endl;
    }

    return 0;
}
