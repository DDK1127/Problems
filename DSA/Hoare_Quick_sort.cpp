#include<bits/stdc++.h>
using namespace std;

int Hoare_partition(vector<int> &v, int l, int r){
    int m = l+(r-l)/2; // avoid sum overflow. 

    if(v[m] < v[l])
        swap(v[m], v[l]);
    if(v[l] > v[r])
        swap(v[l], v[r]);
    if(v[r] < v[m])
        swap(v[r], v[m]);

    int pv = v[m];
    int i = l-1, j = r+1;
    while (1){
        do{
            i++;
        }while (v[i] < pv);
        do{
            j--;
        }while (v[j] > pv);
        if(i >= j)
            return j;
        swap(v[i], v[j]);
    }
}

void Hoare_quicksort(vector<int> &v, int l, int r){
    if(l < r){
        int res = Hoare_partition(v, l, r);
        Hoare_quicksort(v, l, res-1);
        Hoare_quicksort(v, res+1, r);
    }
}

int main(){
    vector<int> v {120, 99, 57, 12, 3, 6, 454, 1, 69, 8};
    Hoare_quicksort(v, 0, v.size()-1);
    
    for(auto it : v)
        cout << it << " ";
    cout << endl;
    return 0;
}