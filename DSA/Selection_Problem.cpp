// Given N distinct numbers, find the K'th smallest number.
// Time Complexity O(N)
#include <bits/stdc++.h>
using namespace std;

int median(vector<int> &v, int l, int r);

int selection_algorithm(vector<int> &v, int l, int r, int k){
    if(r-l+1 <= 5){
        int j, value;
        for(int i = l+1; i <= r; i++){
            value = v[i], j = i;
            while(j-1 >= l && v[j-1] > value)
                v[j--] = v[j-l];
            v[j] = value;
        }
        return l+k;
    } 

    int pivot = median(v, l, r);
    swap(v[l], v[pivot]);

    int i, j, t = v[l];
    for(i = l, j = l+1; j <= r; j++){
        if(v[j] <= t)
            swap(v[++i], v[j]);
    }
    swap(v[l], v[i]);
    int position = i;

    if(position-l == k) 
        return position;
    else if(position-l < k)
        return selection_algorithm(v, position+1, r, k-(position-l+1));
    else
        return selection_algorithm(v, l ,position, k);
}

int median(vector<int> &v, int l, int r){
    int num_median = (r-l+4)/5; // => ceil
    int i, subl, subr, median_idx;
    for(int i = 0; i < num_median; i++){
        subl = l + i*5;
        subr = subl + 4;
        if(subr > r)
            subr = r;
        median_idx = selection_algorithm(v, subl, subr, (subr-subl)/2);
        swap(v[l+i], v[median_idx]);
        cout << "L = " << l << ", R = " << r << endl;
    }
    return selection_algorithm(v, l, l+num_median, num_median/2); 
}

vector<int> v(100000);
int main(){
    int n, m, input;
    while(cin >> n >> m){
        for(int i = 0; i < n; i++){
            cin >> input;
            v[i] = input;
        }
        int idx = selection_algorithm(v, 0, n-1, m);
        cout << "result => " << v[idx] << endl;
    }
    return 0;
}