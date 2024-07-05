#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int n, k, first;
    int p1, p2, w[100], l[100];
    string str1, str2;

    while (cin >> n){
        if(n == 0)
            break;
        if(first++ != 0)
            cout << endl;
        cin >> k;
        int times = k*n*(n-1)/2;
        for(int i = 0; i <= n; i++){
            w[i] = 0, l[i] = 0;
        }
        for(int i = 0; i < times; i++){
            cin >> p1 >> str1; 
            cin >> p2 >> str2;
            if(str1[0] == str2[0]){}
            else{
                if((str1[0] == 'r' && str2[0] == 's') || (str1[0] == 's' && str2[0] == 'p') || (str1[0] == 'p' && str2[0] == 'r')){
                    w[p1]++, l[p2]++;
                }
                else{
                    w[p2]++, l[p1]++;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(w[i]+l[i] == 0)
                cout << "-" << endl;
            else{
                printf("%.3f\n",(float)w[i]/(w[i]+l[i]));
            }
        }
        
    }
    
    return 0;
}