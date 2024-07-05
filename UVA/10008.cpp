#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int times, alphabet[26]={0};
    string str;
    cin >> times;

    while(times-- >= 0){
        getline(cin, str);
        for(int i = 0; i < str.size(); i++){
            if(str[i] >= 'A' && str[i] <= 'Z')
                alphabet[str[i]-'A']++;
            else if(str[i] >= 'a' && str[i] <= 'z')
                alphabet[str[i]-'a']++;
        }
    }
     // sort(alphabet, alphabet+25);
    int max = 0;
    for(int i = 0; i < 26; i++){
        if(alphabet[i] > max)
            max = alphabet[i];
    }
    for(int k = max; k > 0; k--){
        for(int i = 0; i < 26; i++){
            if(alphabet[i] == k)
                cout << (char)(i+65)<< " " << alphabet[i] << endl;
        }
    }
    

    
    return 0;
}
