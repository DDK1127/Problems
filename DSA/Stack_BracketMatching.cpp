#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    stack<char> ss;
    bool check;

    while(cin >> str){
        check = true;

        for(auto &c : str){
            cout << "c = " << c << endl;
            if(c == '(')
                ss.push('(');
            else if(c == ')'){
                if(!ss.empty() && ss.top() == '(' )
                    ss.pop();
                else{
                    check = false;
                    break;
                }
            }
        }
        if(check && ss.empty())
            cout << "You input is correct.\n";
        else
            cout << "You input is uncorrect.\n";
        while (!ss.empty())
            ss.pop();
    }
}