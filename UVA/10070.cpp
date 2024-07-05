#include<iostream>
#include<math.h>
using namespace std;

// Multiples of 3 = the sum of each bits is a multiple of 3.
bool Mulof3(string &str){
    int sum = 0;
    for(int i = 0; i < str.size(); i++)
        sum += str[i]-'0';
    return (sum%3 == 0)? true:false;
} 

// Multiples of 5 = the last bits is a 5 or 0.
bool Mulof5(string &str){
    return (str[str.size()-1] == '5' || str[str.size()-1] == '0')? true:false;
}

// Multiples of 11 = (the sum of odd - sum of even) % 11 = 0.
bool Mulof11(string &str){
    int odd = 0, even = 0;
    for(int i = 0; i < str.size(); i++){
        if(i % 2)
            odd += str[i] - '0';
        else    
            even += str[i] - '0';
    }
    return ((odd-even) % 11 == 0)? true:false;
}

int main(){
    string str;
    // uva presentation error 
    bool blankline = false;
    
    while(cin >> str){

        if(blankline)
            cout << endl;
        blankline = true;

        bool leap = false, hulu = false, bulu = false;
        int year = 0, sum = 0;
        for(int i = 3; i >= 0; i--)
            year += pow(10,i)*(str[str.size()-i-1]-'0');
        if((year%4 == 0 && year%100 != 0) || year % 400 == 0)
            leap = true;
        if(leap)
            cout << "This is leap year." << endl;
        if(Mulof3(str) && Mulof5(str)){
            hulu = true;
            cout << "This is huluculu festival year." << endl;
        }
        if(Mulof5(str) && Mulof11(str) && leap){
            bulu = true;
            cout << "This is bulukulu festival year." << endl;
        }
        if(!leap && !bulu && !hulu)
            cout << "This is an ordinary year." << endl;
    }

    return 0;
}
