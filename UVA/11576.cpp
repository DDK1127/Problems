#include <iostream>
#include <string>
#include <vector>

using namespace std;

void check(vector<char> &vv, string str, int len);

int main()
{
    int times, len, num;
    // len is once string how long.
    // num is the times of string.
    cin >> times;
    while (times-- > 0){
        cin >> len >> num;
        string str;
        vector<char> vv;

        for (int i = 0; i < num; i++){
            cin >> str;
            if (i == 0){
                for (int j = 0; j < len; j++)
                    vv.push_back(str[j]);
            }

            else{
                check(vv, str, len);
            }
        }
        cout << vv.size() << endl;
    }
    return 0;
}

void check(vector<char> &vv, string str, int len){
    string ss;
    for(int i = 0; i < vv.size(); i++){
        ss+=vv[i];
    }

    for(int i = str.size(); i >= 0; i--){
        if(str.substr(0, i) == ss.substr(vv.size()-i, vv.size())){
            ss += str.substr(i, str.size());
            break;
        }
    }

    for(int i = vv.size(); i < ss.size(); i++){
        vv.push_back(ss[i]);
    }
};