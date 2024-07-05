#include<iostream>
using namespace std;

int main(){
    string str;
    // int  hyphens, nn;
    while (cin >> str){
        // hyphens = 0, nn = 0;
        for(int i = 0; i < str.size(); i++){
            switch (str[i])
            {
            case 'A':
            case 'B':
            case 'C':
                cout << 2;
                break;
            case 'D':
            case 'E':
            case 'F':
                cout << 3;
                break;
            case 'G':
            case 'H':
            case 'I':
                cout << 4;
                break;
            case 'J':
            case 'K':
            case 'L':
                cout << 5;
                break;
            case 'M':
            case 'N':
            case 'O':
                cout << 6;
                break;
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
                cout << 7;
                break;
            case 'T':
            case 'U':
            case 'V':    
                cout << 8;
                break;
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
                cout << 9;
                break;
            // case '-':
            //     // hyphens++;
            // case '1':
            // case '0':
            default:
                cout << str[i];
                // nn++;
                break;
            }
        }
        cout << endl;
        // cout << " " << str.size()-nn << " " << hyphens << endl;
    }
    
    return 0;
}