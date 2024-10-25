#include<bits/stdc++.h>
using namespace std;

// Lomuto Partition Scheme
int Lomuto_partition(vector<int> &v, int l, int r){
    int pv = r, i = l-1, j;
    for(j = l; j < r; j++){
        if(v[j] < v[pv])
            swap(v[++i], v[j]);
    }
    swap(v[i+1], v[pv]);

    return i+1;
}

void Lomuto_quicksort(vector<int> &v, int l, int r){
    if(l < r){
        int res = Lomuto_partition(v, l, r);
        // cout << "res" << res << endl;
        Lomuto_partition(v, l, res-1);
        Lomuto_partition(v, res+1, r);
    }
}

int main(){
    vector<int> v1 {120, 99, 57, 12, 3, 6, 454, 1, 69};
    Lomuto_quicksort(v1, 0, v1.size()-1);
    for(auto it : v1)
        cout << it << " ";
    cout << endl;
    return 0;
}