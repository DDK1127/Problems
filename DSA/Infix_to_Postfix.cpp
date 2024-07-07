#include <bits/stdc++.h>
using namespace std;
// operator [^] unfinished.


int priority(char c){
    switch (c){
    case '&': case '|':
        return 1;
    case '>': case '<': case '=':
        return 2;
    case '+': case '-':
        return 3;
    case '*': case '/': case '%':
        return 4;
    // case '^':
    //     return 5;
    default:
        return 0;
    }
}

int main(){
    string str; // 
    cout << "Please input infix format." << endl;
    while(getline(cin , str)){
        stack<char> ss;
        cout << "Postfix is -> ";
        for(int i = 0; i < str.size(); i++){
            switch (str[i]) {
            case '(':
                ss.push(str[i]);
                break;
            case ')':
                while(ss.top() != '('){
                    cout << ss.top() << " ";
                    ss.pop();
                }
                if(ss.top() == '(')
                    ss.pop();
                break;
            case '+': case '-': case '*': case '/': case '%': case '&': case '|': case '>': case '<': case '=':
                while(!ss.empty() && priority(str[i]) <= priority(ss.top())){
                        cout << ss.top() << " ";
                        ss.pop();
                }
                ss.push(str[i]);
                break;
            // unfinished
            // case '^':
            //     while(!ss.empty() && priority(str[i]) > priority(ss.top())){
            //             cout << ss.top() << " ";
            //             ss.pop();
            //     }
            //     ss.push(str[i]);
            //     break;
            default:
                cout << str[i] << " ";
            }
        }
        while(!ss.empty()){
            cout << ss.top() << " ";
            ss.pop();
        }
        cout << endl;
    }

    return 0;
}