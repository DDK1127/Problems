#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int main(){
    string s1, s2;
    while(getline(cin, s1) && getline(cin, s2)){
        if(s1 == "" || s2 == ""){
            cout << "0" << endl;
            continue;
        }
        vector<int> vv(s2.size()+1, 0);

        for(int i = 1; i <= s1.size(); i++){
            for(int j = s2.size(); j >= 1; j--){
                if(s1[i-1] == s2[j-1])
                    vv[j] = vv[j-1]+1;
            }
            for(int j = 1; j <= s2.size(); j++){
                if(s1[i-1] != s2[j-1])
                    vv[j] = max(vv[j], vv[j-1]);
            }
        }
        cout << vv[s2.size()] << endl;
    }
    return 0;
}

// int main(){
//     string str1, str2;
//     while(getline(cin, str1) && getline(cin, str2)){
//         if(str1 == "" || str2 == ""){
//             cout << "0" << endl;
//             continue;
//         }
//         vector<vector<int> > vv(str1.size()+1, vector<int>(str2.size()+1, 0));

//         for(int i = 1; i <= str1.size(); i++){
//             for(int j = 1; j <= str2.size(); j++)
//                 if(str1[i-1] == str2[j-1])
//                     vv[i][j] = vv[i-1][j-1]+1;
//                 else{
//                     vv[i][j] = max(vv[i-1][j], vv[i][j-1]);
//                 }
//         }
//         cout << vv[str1.size()][str2.size()] << endl;

//         vv.clear();
//     }
//     return 0;
// }