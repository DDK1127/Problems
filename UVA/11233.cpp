#include<bits/stdc++.h>
using namespace std;

int main(){
    int l, n;
    cin >> l >> n;
    string input;
    char last_one, last_two;
    bool find;
    vector <pair<string, string> > list(l);

    for(int i = 0; i < l; i++){
        cin >> input;
        list[i].first = input;
        cin >> input;
        list[i].second = input;
    }
    for(int i = 0; i < n; i++){
        cin >> input;
        find = false;
        last_one = input[input.size()-1];
        last_two = input[input.size()-2];
        for(int i = 0; i < l; i++){
            if(input == list[i].first){
                cout << list[i].second << endl;
                find = true;
                break;
            }
        }
        if(!find){
            if(last_one == 'y' && (last_two != 'a' && last_two != 'e' && last_two != 'i' && last_two != 'o' && last_two != 'u')){
                input.erase(input.end()-1);
                cout << input << "ies" << endl;
            }
            else if(last_one == 'o' || last_one == 's' || last_one == 'x')
                cout << input << "es" << endl;
            else if(last_one == 'h' && (last_two == 'c' || last_two == 's'))
                cout << input << "es" << endl;
            else
                cout << input << "s" << endl;
        }
    }

    return 0;
}