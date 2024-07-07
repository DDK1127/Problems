#include "Stack_Helper.h"
#include <stdexcept>
#include <stack>
#include <string>

bool Stack_Bracket_Check(std::string str){
    std::stack<char> ss;
    bool check = true;
    for(auto &c : str){
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
        return true;
    else{
        while (!ss.empty())
            ss.pop();
    }
    return false;
}

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
    case '^':
        return 5;
    default:
        return 0;
    }
}
