#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> ss;
    int times, number, n;

    cin >> times;
    while(times-- > 0){
        int max = -150000;

        cin >> number;
        for(int i = 0; i < number; i++){
            cin >> n;
            if(!ss.empty()){
                set<int>::reverse_iterator it = ss.rbegin();
                if( (*it - n) > max)
                    max = *it-n;
            }
            ss.insert(n);
        }
        cout << max << endl;
        ss.clear();
    }
    return 0;
}