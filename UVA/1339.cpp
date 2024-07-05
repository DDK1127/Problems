#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
    string str1, str2;
    
    while(cin >> str1 >> str2){
        int c1[26] = {0}, c2[26] = {0};
        bool result = true;
        if(str1.size() != str2.size())
            result = false;
        for(int i = 0; i < str1.size(); i++){
            c1[str1[i] - 'A']++;
            c2[str2[i] - 'A']++;
        }
        sort(c1, c1+26);
        sort(c2, c2+26);
        for(int i = 0; i < 26; i++){
            if(c1[i] != c2[i])
                result = false;
        }
        if(result){cout << "YES" << endl;}
        else{cout << "NO"<< endl;}
    }

    return 0;
}